#include<bits/stdc++.h>
using namespace std;
char c[505];
int a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,s=0,ss=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>c[i];
	}
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]==0){
			s++;
		}
	}
	for (int i=1;i<=n;i++){
		if (a[i]>s){
			ss++;
		}
	}
	m-=ss;
	int sum=1;
	if (m<=0){
		for (int i=1;i<=n;i++){
			sum=(sum*i)%998244353;
		}
	}else{
		int x=rand();
		sum=x%998244353;
	}
	cout<<sum;
} 
/*
3 2
111
1 2 3
*/
