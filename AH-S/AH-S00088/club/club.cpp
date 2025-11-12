#include<bits/stdc++.h>
using namespace std;
const int N=100100;
int f[5][N],mx[N];
int a[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(f,0,sizeof(f));
        memset(a,0,sizeof(a));
        memset(mx,0,sizeof(mx));
        int sum=0;
        int n;
        cin>>n;
        int cnta=0,cntb=0,cntc=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%d",&f[j][i]);
                mx[i]=max(mx[i],f[j][i]);
            }
            if(mx[i]==f[1][i])cnta++;
            else if(mx[i]==f[2][i])cntb++;
            else cntc++;
            sum+=mx[i];
        }
        if(cnta<=n/2&&cntb<=n/2&&cntc<=n/2){cout<<sum<<endl;continue;}

        int m=0;
        if(cnta>n/2)m=1;
        else if(cntb>n/2)m=2;
        else m=3;
        int l=0;
        int t1,t2;
        if(m==1)t1=2,t2=3;
        else if(m==2)t1=1,t2=3;
        else t1=1,t2=2;
        for(int i=1;i<=n;i++){
            if(mx[i]!=f[m][i])continue;
            a[++l]=mx[i]-max(f[t1][i],f[t2][i]);
        }
        sort(a+1,a+1+l);
        for(int i=1;i<=l-n/2;i++){
            sum-=a[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}