#include<bits/stdc++.h>
using namespace std;

long long T,n,q[4],x,ans,sum;

struct pos{
	long long a,b,c,num,p;
}s[100005];
bool cmp1(pos l,pos r){
	long long ul=0,ur=0;
	if(l.p==1) ul=1;
	if(r.p==1) ur=1;
	if(ul!=ur) return ul>ur;
	if(ul==0&&ur==0) return 1;
	return min(l.a-l.b,l.a-l.c)<min(r.a-r.b,r.a-r.c);
}
bool cmp2(pos l,pos r){
	long long ul=0,ur=0;
	if(l.p==2) ul=1;
	if(r.p==2) ur=1;
	if(ul!=ur) return ul>ur;
	if(ul==0&&ur==0) return 1;
	return min(l.b-l.a,l.b-l.c)<min(r.b-r.a,r.b-r.c);
}
bool cmp3(pos l,pos r){
	long long ul=0,ur=0;
	if(l.p==3) ul=1;
	if(r.p==3) ur=1;
	if(ul!=ur) return ul>ur;
	if(ul==0&&ur==0) return 1;
	return min(l.c-l.b,l.c-l.a)<min(r.c-r.b,r.c-r.a);
}
bool cmp(pos l,pos r){
	return l.num<r.num;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>T;
	while(T--){
		ans=0,sum=0;
		cin>>n;
		q[0]=q[1]=q[2]=q[3]=0;
		for(long long i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			s[i].p=3;
			s[i].num=i;
			if(s[i].a>=s[i].b&&s[i].a>=s[i].c) s[i].p=1;
			if(s[i].b>=s[i].a&&s[i].b>=s[i].c) s[i].p=2;
			q[s[i].p]++;
			if(s[i].p==1) sum+=s[i].a;
			if(s[i].p==2) sum+=s[i].b;
			if(s[i].p==3) sum+=s[i].c;
			//cout<<i<<' '<<sum<<' '<<s[i].p<<s[i].a<<"orz\n";
		}
		
		for(long long i=1;i<=3;i++){
			if(q[i]>n/2){
				if(i==1){
					sort(s+1,s+n+1,cmp1);
					for(long long j=1;j<=n&&q[i]>n/2;j++){
						ans+=min(s[j].a-s[j].b,s[j].a-s[j].c);
						//if(s[j].b>s[j].c) s[j].p=2;
						//else s[j].p=3;
						q[i]--;
					}
				}
				if(i==2){
					sort(s+1,s+n+1,cmp2);
					for(long long j=1;j<=n&&q[i]>n/2;j++){
						ans+=min(s[j].b-s[j].a,s[j].b-s[j].c);
						//if(s[j].a>s[j].c) s[j].p=1;
						//else s[j].p=3;
						q[i]--;
					}
				}
				if(i==3){
					sort(s+1,s+n+1,cmp3);
					for(long long j=1;j<=n&&q[i]>n/2;j++){
						ans+=min(s[j].c-s[j].b,s[j].c-s[j].a);
						//if(s[j].a>s[j].b) s[j].p=1;
						//else s[j].p=2;
						q[i]--;
					}
				}
			}
		}
		
		cout<<sum-ans<<'\n';
	}
	
	return 0;
}
