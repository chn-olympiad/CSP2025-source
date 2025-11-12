#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
ll t,n,ans,A,B,C,sum;
struct node{
	ll a,b,c;
}p[N],d[N],e[N],f[N];
bool kmp(node a,node b){
	return min(a.a-a.b,a.a-a.c)<min(b.a-b.b,b.a-b.c);
}
bool dmp(node a,node b){
	return min(a.b-a.a,a.b-a.c)<min(b.b-b.a,b.b-b.c);
}
bool wmp(node a,node b){
	return min(a.c-a.a,a.c-a.b)<min(b.c-b.a,b.c-b.b);
}
bool cmpa(node a,node b){
	return a.c-a.b<b.c-b.b;
}
bool cmpb(node a,node b){
	return a.c-a.a<b.c-b.a;
}
bool cmpc(node a,node b){
	return a.b-a.a<b.b-b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t--){
		memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
		memset(f,0,sizeof(f));
		cin>>n;ans=0;sum=0;A=0;B=0;C=0;
		for(int i=1;i<=n;i++) cin>>p[i].a>>p[i].b>>p[i].c;
		for(int i=1;i<=n;i++){
			if(p[i].a>=p[i].b&&p[i].a>=p[i].c){
				A++;sum+=p[i].a;d[A].a=p[i].a,d[A].b=p[i].b;d[A].c=p[i].c;
				continue;
			}
			if(p[i].b>=p[i].a&&p[i].b>=p[i].c){
				B++;sum+=p[i].b;e[B].a=p[i].a,e[B].b=p[i].b;e[B].c=p[i].c;
				continue;
			}
			if(p[i].c>=p[i].a&&p[i].c>=p[i].b){
				C++;sum+=p[i].c;f[C].a=p[i].a,f[C].b=p[i].b;f[C].c=p[i].c;
				continue;
			}
		}
		if(A>n/2){
			sort(d+1,d+A+1,kmp);
			sort(d+1,d+(A-n/2)+1,cmpa);
			for(int i=1;A>n/2;i++){
				if(B<n/2) sum+=(d[i].b-d[i].a),B++;
				else sum+=(d[i].c-d[i].a),C++;
				A--;
			}
			printf("%lld\n",sum);continue;
		}
		if(B>n/2){
			sort(e+1,e+B+1,dmp);
			sort(e+1,e+(B-n/2)+1,cmpb);
			for(int i=1;B>n/2;i++){
				if(A<n/2) sum+=(e[i].a-p[i].b),A++;
				else sum+=(p[i].c-p[i].b),C++;
				B--;
			}
			printf("%lld\n",sum);continue;
		}
		if(C>n/2){
			sort(f+1,f+C+1,wmp);
			sort(f+1,f+(C-n/2)+1,cmpc);
			for(int i=1;C>n/2;i++){
				if(A<n/2) sum+=(f[i].a-f[i].c),A++;
				else sum+=(f[i].b-f[i].c),B++;
				C--;
			}
			printf("%lld\n",sum);continue;
		}
		printf("%lld\n",sum);
	} 
	return 0;
}
