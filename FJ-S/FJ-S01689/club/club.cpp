#include<bits/stdc++.h>
using namespace std;
long long const N=1e7+9;
long long T,n,x=1,y=1,z=1,v[4],ans=0,a[4][N];
struct stu{
	long long a,b;
}b[4];
bool gz(stu x,stu y) {
	return x.a>y.a;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(long long o=1;o<=T;o++) {
		memset(v,0,sizeof v);
		memset(a,0,sizeof a);
		x=y=z=1;
		ans=0;
		cin>>n;
		for(long long i=1;i<=n;i++) {
			cin>>b[1].a>>b[2].a>>b[3].a;
			b[1].b=1;
			b[2].b=2;
			b[3].b=3;
			sort(b+1,b+4,gz);
			ans+=b[1].a;
			v[b[1].b]++;
			if(b[1].b==1) a[b[1].b][x++]=b[1].a-b[2].a;
			if(b[1].b==2) a[b[1].b][y++]=b[1].a-b[2].a;
			if(b[1].b==3) a[b[1].b][z++]=b[1].a-b[2].a;
		}
		if(v[1]>n/2) {
			sort(a[1]+1,a[1]+x+1);
			for(long long i=1;i<=v[1]-n/2+1;i++) ans-=a[1][i];
		}
		if(v[2]>n/2) {
			sort(a[2]+1,a[2]+y+1);
			for(long long i=1;i<=v[2]-n/2+1;i++) ans-=a[2][i];
		}
		if(v[3]>n/2) {
			sort(a[3]+1,a[3]+z+1);
			for(long long i=1;i<=v[3]-n/2+1;i++) ans-=a[3][i];
		}
		cout<<ans<<endl;
	}
	return 0;
}