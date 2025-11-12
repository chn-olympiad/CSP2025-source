#include<bits/stdc++.h>
using namespace std;
//struct s{
	//int a,b,c,cha;
//}a[1000005];
int a[1000005][3];
long long sum,n0,summax;
int sum0[10];
/*int cmp(s a,s b){
	return a.cha>=b.cha;
}*/
void dfs(int n,int k){
	for(int j=1;j<=3;j++){
		if(sum0[j]>n0/2) return ;
	}
	if(n>n0){
		if(sum>=summax){
			summax=sum;
		}
		return;
	}
	for(int j=1;j<=3;j++){
		sum+=a[k][j];
		sum0[j]++;
		dfs(n+1,k+1);
		sum0[j]--;
		sum-=a[k][j];
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n0;
		memset(sum0,0,5);
		for(int j=1;j<=n0;j++){
			for(int k=1;k<=3;k++)
			cin>>a[j][k];
			//a[j].cha=abs(a[j].a-a[j].b);
		}
		//sort(a+1,a+1+n0,cmp);
		//for(int j=1;j<=n0;j++){
			//cout<<a[j].a<<" "<<a[j].b<<endl;
		//}
		dfs(1,1);
		/*for(int j=1;j<=n0/2;j++){
			sum+=max(a[j].a,a[j].b);
		}
		for(int j=n0/2+1;j<=n0;j++){
			sum+=min(a[j].a,a[j].b);
		}*/
		cout<<summax<<endl;
		sum=0,summax=0;
	}
	return 0;
}
