#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],k[100005][5],ans=0;
void dfs(int step,int sum,int sum1,int sum2,int sum3,int n){
	if(step>n){
		int sumk=0;
		for(int i=1;i<=sum1-1;i++)sumk+=a[i];
		for(int i=1;i<=sum2-1;i++)sumk+=b[i];
		for(int i=1;i<=sum3-1;i++)sumk+=c[i];
		ans=max(ans,sumk);
		return ;
	}
	if(sum1<=sum){
		a[sum1]=k[step][1];
		dfs(step+1,sum,sum1+1,sum2,sum3,n);
	}
	if(sum2<=sum){
		b[sum2]=k[step][2];
		dfs(step+1,sum,sum1,sum2+1,sum3,n);
	}
	if(sum3<=sum){
		c[sum3]=k[step][3];
		dfs(step+1,sum,sum1,sum2,sum3+1,n);
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int ttt=1;ttt<=T;ttt++){
		ans=0;
		int n,sum1=1,sum2=1,sum3=1; 
		int k1=0,k2=0,k3=0;
		cin>>n;
		int len=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&k[i][1],&k[i][2],&k[i][3]);
			if(k[i][1]>0){
				k1++;
				a[k1]=k[i][1];
			}
			if(k[i][2]>0){
				k2++;
				b[k2]=k[i][2];
			}
			if(k[i][3]>0){
				k3++;
				c[k3]=k[i][3];
			}
		}
		if(k1>0&&k2==0&&k3==0){
			sort(a+1,a+k1+1);
			long long sum=0;
			for(int i=1;i<=len;i++){
				sum+=a[n-i+1];
			}
			cout<<sum;
		}else if(k2>0&&k1==0&&k3==0){
			sort(b+1,b+k2+1);
			long long sum=0;
			for(int i=1;i<=len;i++){
				sum+=b[n-i+1];
			}
			cout<<sum;
		}else if(k3>0&&k2==0&&k1==0){
			sort(c+1,c+k3+1);
			long long sum=0;
			for(int i=1;i<=len;i++){
				sum+=c[n-i+1];
			}
			cout<<sum;
		}else{
			dfs(1,len,1,1,1,n);
			printf("%d",ans);
		}
		if(ttt!=T){
			cout<<endl;
		}
	}
}
