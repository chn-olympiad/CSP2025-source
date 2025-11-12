#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const int MaxN=2e5+1000,base=131;

int n,q;
ull q1[MaxN],q2[MaxN];
ull r[MaxN];
char s1[2001000],s2[2001000];

int l[MaxN],a[MaxN];

ull qp(ull base,ull power){
	ull result=1;
	while(power){
		if(power&1)result*=base;
		base*=base;
		power>>=1;
	}
	return result;
}

bool check(){
	for(int j=0;'a'<=s1[j]&&s1[j]<='z';j++){
		if(s1[j]!='a'&&s1[j]!='b')return false;
	}
	for(int j=0;'a'<=s2[j]&&s2[j]<='z';j++){
		if(s2[j]!='a'&&s2[j]!='b')return false;
	}
	return true;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	scanf("%d%d",&n,&q);
	scanf("%s%s",s1,s2);
	
	if(check()){
		a[1]=-1;
		for(int j=0;'a'<=s1[j]&&s1[j]<='z';j++){
			if(s1[j]=='b')a[1]=j;
			else if(a[1]!=-1)r[1]++;
			else l[1]++;
		}
		for(int j=0;'a'<=s2[j]&&s2[j]<='z';j++){
			if(s2[j]=='b'){
				a[1]=a[1]-j;
				break;
			}
		}
		for(int i=2;i<=n;i++){
			scanf("%s%s",s1,s2);
			a[i]=-1;
			for(int j=0;'a'<=s1[j]&&s1[j]<='z';j++){
				if(s1[j]=='b')a[i]=j;
				else if(a[i]!=-1)r[i]++;
				else l[i]++;
			}
			for(int j=0;'a'<=s2[j]&&s2[j]<='z';j++){
				if(s2[j]=='b'){
					a[i]=a[i]-j;
					break;
				}
			}
		}
		while(q--){
			scanf("%s%s",s1,s2);
			int acnt=-1,lcnt=0,rcnt=0;
			for(int j=0;'a'<=s1[j]&&s1[j]<='z';j++){
				if(s1[j]=='b')acnt=j;
				else if(acnt!=-1)rcnt++;
				else lcnt++;
			}
			for(int j=0;'a'<=s2[j]&&s2[j]<='z';j++){
				if(s2[j]=='b'){
					acnt=acnt-j;
					break;
				}
			}
			long long ans=0;
			for(int i=1;i<=n;i++){
				if(l[i]<=lcnt&&r[i]<=rcnt&&a[i]==acnt)ans++;
			}
			printf("%lld\n",ans); 
		}
		
		return 0;
	}
	
	
	for(int j=0;'a'<=s1[j]&&s1[j]<='z';j++){
		r[1]++;
		q1[1]=q1[1]*base+1ull*s1[j];
	}
	for(int j=0;'a'<=s2[j]&&s2[j]<='z';j++){
		q2[1]=q2[1]*base+1ull*s2[j];
	}
	for(int i=2;i<=n;i++){
		scanf("%s%s",s1,s2);
		for(int j=0;'a'<=s1[j]&&s1[j]<='z';j++){
			r[i]++;
			q1[i]=q1[i]*base+1ull*s1[j];
		}
		for(int j=0;'a'<=s2[j]&&s2[j]<='z';j++){
			q2[i]=q2[i]*base+1ull*s2[j];
		}
	}
	while(q--){
		scanf("%s%s",s1,s2);
		ull qa=0,qb=0,len=0;
		for(int j=0;'a'<=s1[j]&&s1[j]<='z';j++){
			len++;
			qa=qa*base+1ull*s1[j];
		}
		for(int j=0;'a'<=s2[j]&&s2[j]<='z';j++){
			qb=qb*base+1ull*s2[j];
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			ull l=0;
			while(l+r[i]<=len){
				if(q1[i]*qp(base,l)+(qa-qa/qp(base,l)*qp(base,l))==qa-qa/qp(base,r[i]+l)*qp(base,r[i]+l)){
					ull cnta=qa-qa/qp(base,l)*qp(base,l)+q2[i]*qp(base,l)+qa/qp(base,l+r[i])*qp(base,l+r[i]);
					if(cnta==qb)ans++;
				}
				l++;
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
} 
