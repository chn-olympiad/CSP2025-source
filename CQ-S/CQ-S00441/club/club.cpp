#include<bits/stdc++.h> 
using namespace std;
namespace MYQ{
	int t,n,a[100011][3],sy[100011],ct[3],c[100001],cn;
	long long ans;
	inline int read() {
		int x=0;
		char c=getchar();
		while(c<'0'||'9'<c)
			c=getchar();
		while('0'<=c&&c<='9'){
			x=(x<<1)+(x<<3)+(c^48);
			c=getchar();
		}
		return x;
	}
	int main(){
		t=read();
		while(t--){
			n=read();
			ct[0]=ct[1]=ct[2]=0;
			ans=0;
			for(int i=1;i<=n;i++){
				a[i][0]=read(),a[i][1]=read(),a[i][2]=read();
				if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])
					ans+=a[i][0],sy[i]=0,ct[0]++;
				else
					if(a[i][1]>=a[i][2])
						ans+=a[i][1],sy[i]=1,ct[1]++;
					else
						ans+=a[i][2],sy[i]=2,ct[2]++;
			}
			cn=0;
			for(int j=0;j<3;j++)
				if(ct[j]*2>n){
					for(int i=1;i<=n;i++)
						if(sy[i]==j)
							c[++cn]=min(a[i][j]-a[i][(j+1)%3],a[i][j]-a[i][(j+2)%3]);
					sort(c+1,c+cn+1);
					for(int i=1;i<=ct[j]-n/2;i++)
						ans-=c[i];
				}
			printf("%lld\n",ans);
		}
		return 0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	MYQ::main();
	return 0;
}
