#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[205],b[205],c[205],a1,b1,c1,hap,ans;
//int nall[205];
int pa[205],pb[205],pc[205];
//int mina,minb,minc;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        a1=1;
        b1=1;
        c1=1;
        //mina=0x3f;
        //minb=0x3f;
        //minc=0x3f;
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a[j]>>b[j]>>c[j];
            //nall[j]=a[j]+b[j]+c[j];
            hap=max(max(a[j],b[j]),c[j]);
            if(hap==a[j]){
                pa[a1]=j;
                a1++;
                ans+=a[j];
                continue;
            }
            if(hap==b[j]){
                pb[b1]=j;
                b1++;
                ans+=b[j];
                continue;
            }
            else{
                pc[c1]=j;
                c1++;
                ans+=c[j];
            }
        }
        cout<<ans<<endl;
    }
   return 0;

}
