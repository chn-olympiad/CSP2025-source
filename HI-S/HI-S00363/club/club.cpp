#include<bits/stdc++.h>
using namespace std;
const int PRO_MAX=20005;
int n;
int a[PRO_MAX]= {0},b[PRO_MAX]= {0},c[PRO_MAX]= {0},d[PRO_MAX];
int ans=0;
int ji=0;
int ta=0,tb=0,tc=0;
int dfs(int cj) {
	if(cj>n) {
		return 0;
	}
	if(ta+1<=(n/2)) {
		ta++;
		ji+=a[cj];
		if(cj==n) {
			ans=max(ans,ji);
		} else {
			dfs(cj+1);
		}
		ji-=a[cj];
		ta--;
	}
	if(tb+1<=(n/2)) {
		tb++;
		ji+=b[cj];
		if(cj==n) {
			ans=max(ans,ji);
		} else {
			dfs(cj+1);
		}
		ji-=b[cj];
		tb--;
	}
	if(tc+1<=(n/2)) {
		tc++;
		ji+=c[cj];
		if(cj==n) {
			ans=max(ans,ji);
		} else {
			dfs(cj+1);
		}
		ji-=c[cj];
		tc--;
	}
	return 0;//ÎØÎØÎØÎØÎØ£¬ÖÕÓÚĞŞºÃÊºÉ½´úÂëÁË£¡
}
bool comp(int t1,int t2) {
	return t1>t2;
}
bool cctv(int t1,int t2) {
	int at1=a[t1]-b[t1];
	int at2=a[t2]-b[t2];
	if (at1<0) at1*=(-1);
	if (at2<0) at2*=(-1);
	if(at1>at2) {
		return true;
	}
	return false;
}
int AAA() {
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++) {
		ans+=a[i];
	}
	return 0;
}
int BBB() {
	sort(d+1,d+1+n);
	for(int i=1; i<=n; i++) {
		int h=d[i];
		if(a[h]>b[h]) {
			if(ta+1<=n/2) {
				ans+=a[h];
				ta++;
			} else {
				ans+=b[h];
				tb++;
			}
		} else if(a[h]<b[h]) {
			if(tb+1<=n/2) {
				ans+=b[h];
				tb++;
			} else {
				ans+=a[h];
				ta++;
			}
		} else {
			ans+=a[h];
		}

	}
	return 0;
}
int work() {
	ji=0;
	ans=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>b[i]>>c[i];
		d[i]=i;
	}
	if(n<=30) {
		ans=0;
		dfs(1);
		cout<<ans<<endl;
		return 0;
	}
	bool nob,noc;
	for(int i; i<=n; i++) {
		if(b[i]!=0&&nob) {
			nob=false;
		}
		if(c[i]!=0&&noc) {
			noc=false;
		}
	}
	if(noc&nob) {
		ans=0;
		AAA();
		cout<<ans;
		return 0;
	} else if(noc) {
		ans=0;
		BBB();
		cout<<ans;
		return 0;
	}
	ans=0;
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		work();
	}
	return 0;
}
