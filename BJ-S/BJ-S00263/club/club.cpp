#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N][3],cnt[3],in[N],mem[N];
bool cmp(int x,int y) {return x>y;}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T; cin>>T;
	while (T--) {
		cin>>n;
		for (int i=1;i<=n;i++) {
			for (int j=0;j<3;j++) cin>>a[i][j];
			in[i]=-1;
		}
		cnt[0]=cnt[1]=cnt[2]=0;
		int c,mr=-1,ans=0,tot=0; 
		for (int i=1;i<=n;i++) {
			c=0;
			for (int j=1;j<3;j++)
				if (a[i][j]>a[i][c]) c=j;
			ans+=a[i][c],cnt[c]++,in[i]=c;
		}
		for (int i=0;i<3;i++)
			if (cnt[i]>n/2) mr=i;
		if (mr!=-1) {
			for (int i=1;i<=n;i++) {
				if (in[i]!=mr) continue;
				if (mr==0) mem[++tot]=max(a[i][1],a[i][2])-a[i][0];
				if (mr==1) mem[++tot]=max(a[i][0],a[i][2])-a[i][1];
				if (mr==2) mem[++tot]=max(a[i][0],a[i][1])-a[i][2];
			}
			sort(mem+1,mem+tot+1,cmp);
			for (int i=1;i<=tot-n/2;i++) ans+=mem[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}