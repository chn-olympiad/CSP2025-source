#include <bits/stdc++.h>
using namespace std;

namespace Cherry {
	const int N=1e5+10;
	int T,n;
	priority_queue<int,vector<int>,greater<int>> q[3];
	
	struct stu {
		int x,id;
	}a[N];
	bool cmp(stu x,stu y) { return x.x>y.x||(x.x==y.x&&x.id<y.id); }
	
	inline int read() {
		int ans=0; char ch='l';
		while(ch<'0'||ch>'9') ch=getchar();
		while(ch>='0'&&ch<='9') ans=(ans<<3)+(ans<<1)+ch-'0',ch=getchar();
		return ans;
	}
	
	int main() {
		T=read();
		while(T--) {
			n=read();
			int ans=0;
			for(int i=0;i<3;i++) while(!q[i].empty()) q[i].pop();
			for(int i=1;i<=n;i++) {
				a[0].x=read(),a[1].x=read(),a[2].x=read();
				a[0].id=0,a[1].id=1,a[2].id=2;
				sort(a,a+3,cmp);
				q[a[0].id].push(a[0].x-a[1].x);
				ans+=a[0].x;
			}
			int t=-1;
			for(int i=0;i<3;i++) if((int)q[i].size()>n/2) t=i;
			if(t==-1) printf("%d\n",ans);
			else {
				while((int)q[t].size()>n/2) ans-=q[t].top(),q[t].pop();
				printf("%d\n",ans);
			}
		}

		return 0;
	}
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	Cherry::main();
//	内存:3MB 

	return 0;
}
/*
MAX<=2e9 不需要 long long 
*/
