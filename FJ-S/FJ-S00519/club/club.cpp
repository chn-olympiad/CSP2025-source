#include<bits/stdc++.h>
using namespace std;
long long t,n;
long long aa,bb,cc,lx=0,ly=0,lz=0,ans=0;
bool tmp=0,tmp2=0;
struct node {
	long long a,b,c;
} x[100010];
bool cmp(node xx,node yy) {
	return xx.a>yy.a;
}
void dfs3(long long ii,long long sum) {
	if (ii==n) {
		long long q=0;
		if (lx<n/2) {
			q=max(q,x[ii].a);
		}
		if (ly<n/2) {
			q=max(q,x[ii].b);
		}
		if (lz<n/2) {
			q=max(q,x[ii].c);
		}
		ans=max(ans,sum+q);
		return ;
	}
	if (lx<n/2) {
		lx++;
		dfs3(ii+1,sum+x[ii].a);
		lx--;
	}
	if (ly<n/2) {
		ly++;
		dfs3(ii+1,sum+x[ii].b);
		ly--;
	}
	if (lz<n/2) {
		lz++;
		dfs3(ii+1,sum+x[ii].c);
		lz--;
	}
}
void dfs2(long long ii,long long sum) {
	if (ii==n) {
		long long q=0;
		if (lx<n/2) {
			q=max(q,x[ii].a);
		}
		if (ly<n/2) {
			q=max(q,x[ii].b);
		}
		ans=max(ans,sum+q);
		return ;
	}
	if (lx<n/2) {
		lx++;
		dfs2(ii+1,sum+x[ii].a);
		lx--;
	}
	if (ly<n/2) {
		ly++;
		dfs2(ii+1,sum+x[ii].b);
		ly--;
	}
}
int main() {
	freopen("club.in","r",stdin);
	  freopen("club.out","w",stdout);
	cin >> t;
	while(t--) {
		lx=0,ly=0,lz=0,ans=0;
		tmp=0,tmp2=0;
		cin >> n;
		for(long long i=1; i<=n; i++) {
			cin >> aa >> bb >> cc;
			x[i].a=aa;
			x[i].b=bb;
			x[i].c=cc;
			if (x[i].b!=0||x[i].c!=0) tmp=1;
			if (x[i].c!=0) tmp2=1;
		}
		if (tmp==0) {
			sort(x,x+n+1,cmp);
			for(long long i=1; i<=n/2; i++) {
				ans+=x[i].a;
			}
			cout << ans << endl;
			continue;
		}
		if (tmp2==0) {
			dfs2(1,0);
			cout << ans << endl;
			continue;
		}
		dfs3(1,0);
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
