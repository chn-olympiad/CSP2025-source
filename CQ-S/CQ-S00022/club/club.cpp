#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int t,n,a[MAXN][3],ID[MAXN],d[MAXN],C[3],D[MAXN];
int GetAns(int id){
	int cnt=0,now=0;
	for(int i=1;i<=n;i++){
		if(ID[i]==id)cnt++,D[cnt]=d[i];
	}
	sort(D+1,D+cnt+1);
	for(int i=1;i<=C[id]-n/2;i++){
		now=now+D[i]; 
	} 
	return now;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		C[0]=C[1]=C[2]=0; 
		scanf("%d",&n);
		int ans=0;
		for(int i=1;i<=n;i++){
			ID[i]=0;
			scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
			int Max1=a[i][0],Max2=0;
			if(a[i][1]>=Max1)Max2=Max1,Max1=a[i][1],ID[i]=1;
			else Max2=a[i][1];
			if(a[i][2]>=Max1)Max2=Max1,Max1=a[i][2],ID[i]=2;
			else if(a[i][2]>=Max2)Max2=a[i][2];
			ans=ans+Max1,C[ID[i]]++,d[i]=Max1-Max2;
		}
		if(C[0]>n/2)ans=ans-GetAns(0);
		else if(C[1]>n/2)ans=ans-GetAns(1);
		else if(C[2]>n/2)ans=ans-GetAns(2);
		printf("%d\n",ans);
	}
	return 0; 
} 
