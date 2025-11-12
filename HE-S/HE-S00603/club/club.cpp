#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long t,n,cnt[4],ans;
struct node{
	long long a;
	long long b;
	long long c;
	long long maxx;
	long long ty;
	long long z;
	long long to;
}s[N];
bool cmpp(node x,node y){
	if(x.z>y.z) return true;
	else if(x.maxx>y.maxx && x.z==y.z) return true;
	return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld %lld %lld",&s[i].a,&s[i].b,&s[i].c);
			s[i].maxx=max(max(s[i].a,s[i].b),s[i].c);
			if(s[i].a==s[i].maxx){
				s[i].ty=1;
				s[i].z=s[i].a-max(s[i].b,s[i].c);
				if(s[i].b>s[i].c) s[i].to=2;
				else s[i].to=3;
			}else if(s[i].b==s[i].maxx){
				s[i].ty=2;
				s[i].z=s[i].b-max(s[i].a,s[i].c);
				if(s[i].a>s[i].c) s[i].to=1;
				else s[i].to=3;
			}else{
				s[i].ty=3;
				s[i].z=s[i].c-max(s[i].a,s[i].b);
				if(s[i].a>s[i].b) s[i].to=1;
				else s[i].to=2;
			}
		}
		sort(s+1,s+n+1,cmpp);
		for(int i=1;i<=n;i++){
			ans+=s[i].maxx;
//			cout<<s[i].maxx<<" "<<s[i].z<<" "<<s[i].ty<<endl;
			cnt[s[i].ty]++;
			
			if(cnt[1]>(n/2) || cnt[2]>(n/2) || cnt[3]>(n/2)) ans-=s[i].z,cnt[s[i].to]++;
			if(cnt[1]>(n/2)) cnt[1]--;
			if(cnt[2]>(n/2)) cnt[2]--;
			if(cnt[3]>(n/2)) cnt[3]--;
//			cout<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<endl;
		}
		printf("%lld\n",ans);
		ans=0;
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
	}
	return 0;
}
