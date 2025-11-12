#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a,sum,p,q;
    cin>>n>>m;
    int nm=n*m;
    vector<int>v;
    for(int i=1;i<=nm;i++){
        int c;
        cin>>c;
        if(i==1)a=c;
        v.push_back(c);
    }
    sort(v.begin(),v.end(),cmp);
    int x=1,y=1;
    p=0,q=1;
    for(int i=0;i<nm;i++){
        if(a==v[i])cout<<x<<" "<<y;
        else{
            p++;
            //cout<<x<<" "<<y
            if(q%2==0){
                if(y!=1)y--;
                //else if(y==1)x++;
            }
            else if(q%2==1){
                if(y!=n)y++;
            }
            if(p==n){
                q++;
                p=0;
                x++;
            }

        }

    }

    return 0;
}
