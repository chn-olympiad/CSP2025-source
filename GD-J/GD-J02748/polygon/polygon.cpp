#include<bits/stdc++.h>
using namespace std;
const int M=1e5,mod=998244353;
long long n,k,a[M],sum,s[M];
long long sss(int a){
	long long x=1,x_=1;
	for(int i = 2;i <= a;i++){
		x=(x*a)%mod;
	}for(int i = n;i >=n-a+1;i--){
		x_=(x*a)%mod;
	}return (x_/x)%mod;
}
void dfs(int x,int m,long long q,int i){
	//cout << x<<' '<<m<<' '<<q<<' '<<q-a[i] <<' '<<i<<'\n';
	if(x==m){
		if(q-a[i-1]>a[i-1]){
			sum++;
		}return;
	}if(i==n-1)return;
	dfs(x+1,m,q+a[i],i+1);
	dfs(x,m,q,i+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >>a[i];
	}sort(a,a+n);
	if(n==3){
		for(int i = 0;i < n-2;i++){
			for(int j = i+1;j < n-1;j++){
				for(int k = j+1;k<n;k++){
					if(i+j>k)sum++;
				}
			}
		}cout << sum;
	}
	else if(a[100]==1){
		for(int i =3 ;i <= n;i++){
			sum=(sum+sss(i))%mod;
		}cout << sum;
	}
	else{
		for(int i =3;i <=n;i++){
			dfs(0,i,0,0);
		}cout << sum;
	}
	return 0;
}//5 1 2 3 4 5
