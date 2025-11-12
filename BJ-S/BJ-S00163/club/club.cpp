#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,a[100005],b[100005],c[100005];
int l[100005],r[100005],t[5],p[100005],v[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        t[1]=0;t[2]=0;t[3]=0;
        cin>>n;
        int sum=0;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(a[i]>=b[i]&&a[i]>=c[i]){
               l[i]=abs(a[i]-b[i]);
               r[i]=abs(a[i]-c[i]);
               t[1]++;
               sum+=a[i];
               p[i]=1;
            }
            else if(b[i]>=c[i]&&b[i]>=a[i]){
               l[i]=abs(b[i]-a[i]);
               r[i]=abs(b[i]-c[i]);
               t[2]++;
               sum+=b[i];
               p[i]=2;
            }
            else if(c[i]>=b[i]&&c[i]>=b[i]){
               l[i]=abs(c[i]-a[i]);
               r[i]=abs(c[i]-b[i]);
               t[3]++;
               sum+=c[i];
               p[i]=3;
            }
        }
        int q=0;
        for(int i=1;i<=3;i++){
            if(t[i]>n/2){
               q=i;
               break;
            }
        }
        int ans=0,o=0;
        for(int i=1;i<=n;i++){
            if(p[i]==q){
               v[++o]=min(l[i],r[i]);
            }
        }
        sort(t+1,t+o+1);
        for(int i=1;i<=(o-n/2);i++){
            ans+=v[i];
        }
        cout<<sum-ans<<endl;
    }
    return 0;
}
