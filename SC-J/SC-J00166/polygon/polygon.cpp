#include<bits/stdc++.h>

using namespace std;
int a[110];int n;
bool hsh[30];int jg[30];
long long ans=0;
long long f[5010][5000];long long mod=998244353;
//f[a][b]a阶乘的质因数b的指数 
long long ksm(long long ds,long long zs){
	long long tmp=ds;long long ans1=1;
	while(zs>0){
		if(zs&1==1){
			ans1=(ans1*tmp)%mod;
		}
		tmp=(tmp*tmp)%mod;
		zs>>=1;
	}
	return ans1;
}
void print(int sum,int x){
	if(x*2<sum){
		ans++;
	}
}
void dfs(int k,int x,int sum){
	for(int i=1;i<=n;i++){
		if(i>jg[k-1]&&hsh[i]==0){
			sum+=a[i];
			jg[k]=i;
			hsh[i]=1;
			if(k==x){
				print(sum,a[i]);
			}else{
				dfs(k+1,x,sum);
			}
			
			sum-=a[i];
			jg[k]=0;
			hsh[i]=0;
		}
	}
}
void zysfj(int a){
	int a1=a;
	long long tmp[5010]={0};
	for(int i=2;i*i<=a1;i++){
		while(a%i==0){
			a/=i;
			tmp[i]++;
		}
	}
	for(int i=1;i<=n;i++){
		f[a1][i]=f[a1-1][i]+tmp[i];
	}
}
long long solve(int m){
	long long tmp[5010]={0};
	for(int i=1;i<=n;i++){
		tmp[i]=f[n][i]-f[n-m][i]-f[m][i];
	}
	long long ans1=1;
	for(long long i=1;i<=n;i++){
		if(tmp[i]>0){
			long long k=ksm(i,tmp[i]);
			ans1=(ans1*k)%mod; 
		}
	}
}
int main()
{
	cin>>n;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	if(n<=20){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}	
		sort(a+1,a+n+1);
		for(int i=3;i<=n;i++){
			jg[0]=0;
			dfs(1,i,0);
		}
		cout<<ans;
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		} 
		f[1][1]=1;
		for(int j=2;j<=n;j++){
			zysfj(j);
		}
		for(int i=3;i<=n;i++){
			ans+=solve(i);
			ans=ans%mod;
		}
		
		cout<<ans;
	}
	return 0;
}