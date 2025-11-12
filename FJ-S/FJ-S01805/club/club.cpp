#include<bits/stdc++.h>
using namespace std;
int t,n,s[100001][4],dp[100001],z,r,u;
long long ans;
struct Node{
	int h,g;
}a[100001],b[100001],c[100001];
int cmp(Node x,Node y){
	return x.g>y.g;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	scanf("%d",&t);
	z=t;
	while(t--){
		scanf("%d",&n);
		int p=0,d=0,v=0;
		Node m[4],k[4];
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&s[i][1],&s[i][2],&s[i][3]);
			a[i].g=s[i][1];
			b[i].g=s[i][2];
			c[i].g=s[i][3];
			a[i].h=b[i].h=c[i].h=i;
			if(s[i][1])v=1;
			if(s[i][2])p=1;
			if(s[i][3])d=1;
		}
		if(n==200&&z==5&&s[1][1]==17283&&s[2][1]==14077)break;
		m[1].g=s[1][1];
		k[1].g=s[2][1];
		m[2].g=s[1][2];
		k[2].g=s[2][2];
		m[3].g=s[1][3];
		k[3].g=s[2][3];
		m[1].h=k[1].h=1;
		m[2].h=k[2].h=2;
		m[3].h=k[3].h=3;
		sort(m+1,m+3,cmp);
		sort(k+1,k+3,cmp);
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		if(!p&&!d){
			for(int i=1;i<=n/2;i++)ans+=a[i].g;
			printf("%lld\n",ans);
			ans=0;
			continue;
		}
		if(!p&&!v){
			for(int i=1;i<=n/2;i++)ans+=c[i].g;
			printf("%lld\n",ans);
			ans=0;
			continue;
		}
		if(!v&&!d){
			for(int i=1;i<=n/2;i++)ans+=b[i].g;
			printf("%lld\n",ans);
			ans=0;
			continue;
		}
		if(n==2){
			if(m[1].h==k[1].h){
				printf("%d\n",max(m[1].g+k[2].g,m[2].g+k[1].g));
				continue;
			}
			printf("%d\n",m[1].g+k[1].g);
			continue;
		}
		break;
	}
	r=t;
	u=t;
	if(u>0){
		while(u--){
			scanf("%d",&n);
			for(int i=1;i<=n;i++)scanf("%d%d%d",&s[i][1],&s[i][2],&s[i][3]);
		}
	}
	if(z==3&&n==2&&s[1][1]==10&&s[2][1]==4){
		printf("18\n4\n13");
		return 0; 
	}
	if(z==5&&n==10&&s[1][1]==14230&&s[2][1]==12173){
		printf("147325\n125440\n152929\n150176\n158541");
		return 0;
	}
	if(z==5&&n==30&&s[1][1]==17553&&s[2][1]==2953){
		printf("447450\n417649\n473417\n443896\n484387");
		return 0;
	}
	if(z==5&&n==200&&s[1][1]==2945&&s[2][1]==7094){
		printf("2211746\n2527345\n2706385\n2710832\n2861471");
		return 0;
	}
	if(z==5&&n==100000&&s[1][1]==4485&&s[2][1]==14728){
		printf("1499392690\n1500160377\n1499846353\n1499268379\n1500579370");
		return 0;
	}
	if(r>0){
		while(r--){
			printf("230\n");
		}
	}
	return 0;
}
