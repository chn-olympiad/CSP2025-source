#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a;
    int x;
    for(int i=0;i<(n*m);++i){
        cin>>x;
        a.push_back(x);
    }
    x=a[0];
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int t;
    for(int i=0;i<(int)a.size();++i){
        if(a[i]==x){
            t=i;
            break;
        }
    }
    int k=t/n;
    int f=(t-k*n);
 //   cout<<"t:"<<t<<endl;
 //   cout<<"k:"<<k<<endl;
 //   cout<<"f:"<<f<<endl;
    if(k%2){
        cout<<(k+1)<<" "<<(n-f);
    }else{
        cout<<(k+1)<<" "<<(f+1);
    }
    return 0;
}