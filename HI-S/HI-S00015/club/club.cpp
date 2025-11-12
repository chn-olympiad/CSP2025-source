#include<bits/stdc++.h>
#define afor(i,x,y) for(int i=(x);i<=(y);i++)
#define bfor(i,x,y) for(int i=(x);i>=(y);i--)
using namespace std;
typedef long long ll;
const int N=1e5+10;
int T,n,tot[4],a[N][4];
int q[4][N];
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        afor(i,1,3) tot[i]=0;
        int ans=0;
        afor(i,1,n) {
            afor(j,1,3) scanf("%d",&a[i][j]);
            int mx=-1,sec=0,k;
            afor(j,1,3) if(a[i][j]>mx) mx=a[i][j],k=j;
            afor(j,1,3) if(j!=k) sec=max(sec,a[i][j]);
            ans+=mx,q[k][++tot[k]]=mx-sec;
        }
        afor(i,1,3) if(tot[i]>n/2) {
            sort(q[i]+1,q[i]+tot[i]+1);
            afor(j,1,tot[i]-n/2) ans-=q[i][j];
        }
        printf("%d\n",ans);
    }
	return 0;
}