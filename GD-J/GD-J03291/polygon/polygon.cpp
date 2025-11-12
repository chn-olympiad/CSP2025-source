#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5007];
int N=998244353;
int speed_pow(int n,int x){
	 if(x==0)return 1;
	 int num=speed_pow(n,x/2);
	 if(x%2)return num*num*n%N;
	 return num*num%N;
}
int n;
int ans=0;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int p,int s,int m,int num){
	//cout<<p<<' '<<s<<' '<<m<<' '<<num<<endl;
	if(s>2*m&&num>=3){
		ans+=speed_pow(2,n-p+1);
		ans%=N;
		return;
	}
	if(p>n)return;
	dfs(p+1,s,m,num);
	dfs(p+1,s+a[p],max(m,a[p]),num+1);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int num=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num=max(num,a[i]);
	}
	//cout<<num;
	if(num==1){
		cout<<speed_pow(2,n)-n*(n-1)/2-n-1;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	dfs(1,0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	//system("fc polygon.out ans.out");
	return 0;
}
