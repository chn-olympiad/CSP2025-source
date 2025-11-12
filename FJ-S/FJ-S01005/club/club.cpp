#include<bits/stdc++.h>
using namespace std;
void work(){
	long long n;
	cin>>n;
	long long a,b,c;
	long long i;
	long long P[n],W[n];
	long long bukt[20001];
	long long acnt=0,bcnt=0,ccnt=0,mcnt,m;
	int opt[n];
	long long ans=0;
	for(i=0;i<n;i++){
		scanf("%lld %lld %lld",&a,&b,&c);
		if(a>=b&&a>=c){
			P[i]=a;
			opt[i]=1;
			ans+=P[i];
			acnt++;
			if(b>c){
				W[i]=P[i]-b; 
			}
			else W[i]=P[i]-c;
		}
		else if(b>=a&&b>=c){
			P[i]=b;
			opt[i]=2;
			ans+=P[i];
			bcnt++;
			if(a>c){
				W[i]=P[i]-a; 
			}
			else W[i]=P[i]-c;
		}
		else if(c>=b&&c>=a){
			P[i]=c;
			opt[i]=3;
			ans+=P[i];
			ccnt++;
			if(a>b){
				W[i]=P[i]-a; 
			}
			else W[i]=P[i]-b;
		}
	}
	mcnt=max(acnt,max(bcnt,ccnt));
	if(mcnt<=n/2){
		printf("%lld\n",ans);
		return;
	}
	if(mcnt==acnt)m=1;
	if(mcnt==bcnt)m=2;
	if(mcnt==ccnt)m=3;
	memset(bukt,0,sizeof(bukt));
	for(i=0;i<n;i++){
		if(opt[i]==m){
			bukt[W[i]]++;
		}
	}
	long long j=n/2;
	for(i=0;i<=20001&&j<mcnt;i++){
		if(bukt[i]>0){
			ans-=i;
			bukt[i]--;
			j++;
			i--;
		}
	}
	printf("%lld\n",ans);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin>>t;
	while(t--)work();
	return 0;
}
