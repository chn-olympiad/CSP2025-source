#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector< pair<int,int> > vp(n*m);
    for(int i=0;i<n*m;i++){
        cin>>vp[i].first;
        vp[i].second=i;
    }
    sort(vp.begin(),vp.end(),greater< pair<int,int> >());
    int pos=0;
    for(int i=0;i<n*m;i++){
        if(vp[i].second==0){
            pos=i;
            break;
        }
    }
    cout<<(pos/n+1)<<" ";
    if((pos/n)%2==0){
        cout<<(pos%n+1);
    }
    else{
        cout<<(m-pos%n);
    }
    //cout<<"END";
    return 0;
}
