#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,m=0,a,b,c,sum=0;
    int bb=0,cc=0,bbb[100010];
    cin>>t;
    while(t--){
        m=0,sum=0,bb=0,cc=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a>>b>>c;
            bb+=b,cc+=c,bbb[i]=a;
            m+=max(max(a,b),c);
        }
        sort(bbb+1,bbb+n+1,cmp);
        if(bb+cc==0){
            for(int i=1;i<=n/2;i++){
                sum+=bbb[i];
            }
            cout<<sum<<endl;
            return 0;
        }
        cout<<m<<endl;
    }
    return 0;
}
