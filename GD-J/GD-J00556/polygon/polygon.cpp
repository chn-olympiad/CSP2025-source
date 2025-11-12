#include<bits/stdc++.h>
using namespace std;
const int N=10009;
int n;
int a[N];
long long sum=0;
void fi(int fa,int maxn,long long len,int cnt){ 
	for(int i=fa+1;i<=n;i++){
		int maxk=max(maxn,a[i]);//木棍最大长度 
		int lenk=len+a[i];
		if(lenk>maxk*2 && cnt>=2)sum++;//可以组合增加方案数 
		fi(i,maxk,lenk,cnt+1);
	}
	sum=sum%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}int ans=0;
	for(int i=1;i<=n;i++){
		fi(i,a[i],a[i],1);
	}
	cout<<sum%998244353;
	return 0;
} 
