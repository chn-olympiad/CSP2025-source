#include <bits/stdc++.h>
using namespace std;
int f1[1919810];
int f2[1919810];
int f3[1919810];
int v1[1919810];
int v2[1919810];
int v3[1919810];
void sj(){
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    int mx=0;
    if(a+e>mx) mx=a+e;
    if(a+f>mx) mx=a+f;
    if(b+d>mx) mx=b+d;
    if(b+f>mx) mx=b+f;
    if(c+d>mx) mx=c+d;
    if(c+e>mx) mx=c+e;
    cout<<mx;
    return;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin>>n;
        for(int i=0;i<=n;i++) f1[i]=0;
        for(int i=0;i<=n;i++) f2[i]=0;
        for(int i=0;i<=n;i++) f3[i]=0;
        for(int i=0;i<=n;i++) v1[i]=0;
        for(int i=0;i<=n;i++) v2[i]=0;
        for(int i=0;i<=n;i++) v3[i]=0;
        if(n==2){
            sj();
            return 0;
        }
        // bag? f[j]=max(f[j],f[j-w[i]]+v[i]);
        for(int i=1;i<=n;i++)
            cin>>v1[i]>>v2[i]>>v3[i];
        for(int i=1;i<=n;i++){
            for(int j=i;j>=1;j--){
                if(v1[i]>v2[i]&&v1[i]>v3[i]){
                    f1[j]=max(f1[j],f1[j-1]+v1[i]);
                    f2[j]=max(f2[j],f2[j-1]);
                    f3[j]=max(f3[j],f3[j-1]);
                } else if(v2[i]>v1[i]&&v2[i]>v3[i]){
                    f1[j]=max(f1[j],f1[j-1]);
                    f2[j]=max(f2[j],f2[j-1]+v2[i]);
                    f3[j]=max(f3[j],f3[j-1]);
                } else if(v3[i]>v1[i]&&v3[i]>v2[i]){
                    f1[j]=max(f1[j],f1[j-1]);
                    f2[j]=max(f2[j],f2[j-1]);
                    f3[j]=max(f3[j],f3[j-1]+v3[i]);
                }
            }
        }
        cout<<f1[n/2]+f2[n/2]+f3[n/2]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
