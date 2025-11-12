#include<bits/stdc++.h>
using namespace std;
#define N 100010

long long read(){
	long long res=0;char c=getchar();bool flag=0;
	while(c<'0'||c>'9'){
		flag|=(c=='-');
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=(res<<1)+(res<<3)+(c^48);
		c=getchar();
	}
	return res * ( flag ? -1 : 1 );
}

struct node{
	long long a,b,c;
} num[N],clubA[N],clubB[N],clubC[N];
bool cmp(node x,node y){
	return max(x.a,max(x.b,x.c))>max(y.a,max(y.b,y.c));
}

int n,cntA,cntB,cntC;
long long ans=0;

void Cecilia(){
	n=read();ans=0;
	cntA=cntB=cntC=0;
	for(int i=1;i<=n;i++){
		num[i].a=read();
		num[i].b=read();
		num[i].c=read();
		if(num[i].a>=num[i].b&&num[i].a>=num[i].c){
			num[i].b-=num[i].a;
			num[i].c-=num[i].a;
			ans+=num[i].a;
			num[i].a=-1e16;
			clubA[++cntA]=num[i];
		}
		else if(num[i].b>=num[i].a&&num[i].b>=num[i].c){
			num[i].a-=num[i].b;
			num[i].c-=num[i].b;
			ans+=num[i].b;
			num[i].b=-1e16;
			clubB[++cntB]=num[i];
		}
		else{
			num[i].a-=num[i].c;
			num[i].b-=num[i].c;
			ans+=num[i].c;
			num[i].c=-1e16;
			clubC[++cntC]=num[i];
		}
	}
	sort(clubA+1,clubA+1+cntA,cmp);
	sort(clubB+1,clubB+1+cntB,cmp);
	sort(clubC+1,clubC+1+cntC,cmp);
	int i=1;
	while(cntA*2>n){
		ans+=max(clubA[i].b,clubA[i].c);
		i++;
		cntA--;
	}
	i=1;
	while(cntB*2>n){
		ans+=max(clubB[i].a,clubB[i].c);
		i++;
		cntB--;
	}
	i=1;
	while(cntC*2>n){
		ans+=max(clubC[i].a,clubC[i].b);
		i++;
		cntC--;
	}
	printf("%lld\n",ans);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int loli=read();
	while(loli--) Cecilia();
	return 0;
}

