#include <bits/stdc++.h>
using namespace std;
int t,n,maxn,a1,a2,a3,midi,b[100005][3],sum,c[1000005];
struct node{
	int i1,i2,i3;
	int maxni;
}a[100005];
bool cmp(node x,node y){
	return x.maxni>y.maxni;
}
void dfs(int k,int sum){
	if(k==n+1){
		maxn=max(maxn,sum);
		return ;
	}
	if(a1<midi){
		a1++;
		dfs(k+1,sum+a[k].i1);
		a1--;
	}
	if(a2<midi){
		a2++;
		dfs(k+1,sum+a[k].i2);
		a2--;
	}
	if(a3<midi){
		a3++;
		dfs(k+1,sum+a[k].i3);
		a3--;
	}
} 
int dfs2(int k,int sum){
	if(k==n+1){
		maxn=max(maxn,sum);
		return maxn;
	}
	if(c[k]!=0){
		dfs(k+1,c[k]);
	}
	else{
		if(a1<midi){
			a1++;
			c[k]=max(c[k],dfs2(k+1,sum+a[k].i1));
			a1--;
		}
		if(a2<midi){
			a2++;
			c[k]=max(c[k],dfs2(k+1,sum+a[k].i2));
			a2--;
		}	
	}
	
}
void A(){
	for(int i=1;i<=n/2;i++){
		sum+=a[i].maxni;
	}
	return ;
} 
void B(){
	dfs2(1,0);
	printf("%d\n",maxn);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		bool b1=0,b2=0,b3=0;
		//memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		maxn=0;
		scanf("%d",&n);
		a1=0;a2=0;a3=0;midi=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].i1,&a[i].i2,&a[i].i3);
			if(a[i].i1!=0){
				b1=1;
			}
			if(a[i].i2!=0){
				b2=1;
			}
			if(a[i].i3!=0){
				b3=1;
			}
			a[i].maxni=max(a[i].i1,a[i].i2);
			a[i].maxni=max(a[i].maxni,a[i].i3);
			b[i][1]=a[i].i1;
			b[i][2]=a[i].i2;
			b[i][3]=a[i].i3;
		}
		sort(a+1,a+n+1,cmp);
		if(b3==0 && b2==0){
			A();
			printf("%d\n",sum);
		}
		/*
		else if(b3==0){
			B();
		}
		*/
		else if(n<=10){
			dfs(1,0);
			printf("%d\n",maxn);	
		}
		/*
		for(int i=1;i<=n;i++){
			for(int j=midi;j>=1;j--){
				for(int k=1;k<=3;i++){
					dp[i][j]=max(dp[i][j],dp[i][j-1]+b[i][k]);
					cout<<dp[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<endl;
		}
		*/
		 
		else{
			for(int i=1;i<=n;i++){
			if(a[i].maxni==a[i].i1 && a1<midi){
				a1++;
				sum+=a[i].maxni;
			}
			else if(a[i].maxni==a[i].i2 && a2<midi){
				a2++;
				sum+=a[i].maxni;
			}
			else if(a[i].maxni==a[i].i3 && a3<midi){
				a3++;
				sum+=a[i].maxni;
				}
			}
			printf("%d\n",sum);	
		}
		
		/*
		for(int i=1;i<=n;i++){
			for(int j=0;j<=midi;j++){
				printf("%d ",dp[i][j]);
			}
			printf("\n");
		}
		*/
		
	}
	return 0;
}
