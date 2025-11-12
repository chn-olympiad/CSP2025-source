#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c,A[100010],v1,v2,v3,flag=1,ans;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        flag=1;
        ans=0;
        v1=0;
        v2=0;
        v3=0;
        memset(A,0,sizeof(A));
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a>>b>>c;
            A[i]=a;
            if(a!=0&&b!=0&&c!=0){
                flag=0;
            }
            if(a>b){
                if(a>c){
                    v1+=a;
                }else{
                    v3+=c;
                }
            }else if(b>c){
                v2+=b;
            }else{
                v3+=c;
            }
        }
        if(flag==1){
            sort(A,A+n,cmp);
            for(int i=0;i<n/2;i++){
                ans+=A[i];
            }
            cout<<ans<<endl;
            continue;
        }
        cout<<v1+v2+v3<<endl;
    }
    return 0;
}