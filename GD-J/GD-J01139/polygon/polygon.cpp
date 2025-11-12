#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a[5010];
const long long modd=998244353;
long long f[5010];

int main(){
									//文件读写
									//数据范围 
									//输出格式 
									//别挂分pls 
									//一等pls 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int i,j;
	bool flag=0;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=1;
	}
	if(!flag){
		long long ans=0;
		long long sum=0;
		for(i=3;i<=n;i++){
			sum+=i-2;
			sum%=modd;
			f[i]=f[i-1]+sum;
			ans+=f[i];
			ans%=modd;
			f[i]%=modd;
		}
		cout<<ans;
	}else{
		cout<<0;
	}
	return 0;
}
