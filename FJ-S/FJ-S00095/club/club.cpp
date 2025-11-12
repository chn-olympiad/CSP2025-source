#include<bits/stdc++.h>
using namespace std;
struct qwe {
	long long gh[4];
	long long s1;
	long long s2;
	long long s3;
} fs[100010];
long long xa[100010];
long long xb[100010];
long long xc[100010];
bool cmp(qwe a,qwe b) {
	return (a.gh[a.s1]-a.gh[a.s2])>(b.gh[b.s1]-b.gh[b.s2]);
}
int main() {
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(long long ts=1; ts<t+1; ts++) {
		long long n;
		cin>>n;
		for(long long i=1; i<=n; i++) {
			cin>>fs[i].gh[1]>>fs[i].gh[2]>>fs[i].gh[3];
			if(fs[i].gh[1]>=fs[i].gh[2]&&fs[i].gh[1]>=fs[i].gh[3]) {
				fs[i].s1=1;
				if(fs[i].gh[2]>=fs[i].gh[3]) {
					fs[i].s2=2;
					fs[i].s3=3;
				} else {
					fs[i].s2=3;
					fs[i].s3=2;
				}
			} else if(fs[i].gh[2]>=fs[i].gh[1]&&fs[i].gh[2]>=fs[i].gh[3]) {
				fs[i].s1=2;
				if(fs[i].gh[1]>=fs[i].gh[3]) {
					fs[i].s2=1;
					fs[i].s3=3;
				} else {
					fs[i].s2=3;
					fs[i].s3=1;
				}
			} else {
				fs[i].s1=3;
				if(fs[i].gh[1]>=fs[i].gh[2]) {
					fs[i].s2=1;
					fs[i].s3=2;
				} else {
					fs[i].s2=2;
					fs[i].s3=1;
				}
			}
		}
		sort(fs+1,fs+n+1,cmp);
		long long ma=0;
		long long mb=0;
		long long mc=0;
		for(long long i=1; i<=n; i++) {
			if(fs[i].s1==1) {
				ma++;
				xa[ma]=i;
			} else if(fs[i].s1==2) {
				mb++;
				xb[mb]=i;
			} else {
				mc++;
				xc[mc]=i;
			}
		}
		long long ans=0;
		for(long long i=1; i<=min(n/2,ma); i++) {
			ans+=fs[xa[i]].gh[1];
		}
		for(long long i=1; i<=min(n/2,mb); i++) {
			ans+=fs[xb[i]].gh[2];
		}
		for(long long i=1; i<=min(n/2,mc); i++) {
			ans+=fs[xc[i]].gh[3];
		}
		for(long long i=min(n/2,ma)+1; i<=ma; i++) {
			ans+=fs[xa[i]].gh[fs[xa[i]].s2];
		}
		for(long long i=min(n/2,mb)+1; i<=mb; i++) {
			ans+=fs[xb[i]].gh[fs[xb[i]].s2];
		}
		for(long long i=min(n/2,mc)+1; i<=mc; i++) {
			ans+=fs[xc[i]].gh[fs[xc[i]].s2];
		}
		cout<<ans<<endl;
	}
	return 0;
}

















