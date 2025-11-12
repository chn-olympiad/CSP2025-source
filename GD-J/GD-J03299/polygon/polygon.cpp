#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,num;
int a[5005],b[5005];
int dfs(int m,int sum,int maxn){
	//cout <<sum<<" "<<maxn<<endl;
	if(maxn<sum){
		//cout <<sum<<" "<<maxn<<endl;
		num++;
		num%=998244353;
	}
	for(int i=m-1;i>=1;i--){
		if(b[i]==1)continue;
		//cout <<i<<endl;
		b[i]=1;
		dfs(i,sum+a[i],maxn);
		b[i]=0;
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	int flag=0,j=0;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		if(a[i]!=1){
			flag=1;
		}
		
	}
//	cout <<flag<<endl;
	if(flag==0){
		long long l=n,r=1,i=2;
		num+=n;
		while(i<=n/2){
			l*=(n-i+1);
			r*=i;
			num+=(l/r);
			i++;
		}
	//	cout <<num<<endl;
		num*=2;
		if(n%2==0){
			num-=(l/r);
		}
		cout <<num+1;
		return 0;
	}
	sort(a+1,a+1+n);
	/*
	for(int i=1;i<=n;i++){
		cout <<a[i]<<" ";
	}
	cout <<endl;
	*/
	for(int i=n;i>=1;i--){
		b[i]=1;
		dfs(i,a[i],a[i]*2);
	 	//cout <<num<<endl<<endl;
		b[i]=0;
	}
	cout <<num;
	return 0;
}
/*
5
2 2 3 8 10
*/
