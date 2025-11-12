#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
long long A(int a,int b){
	long long sum=1;
	while(b--){
		sum*=a;
		sum=sum%998244353;
		a--;
	}
	return sum;
}
int C(int a,int b){
	return A(a,b)/A(b,b);
}

int n;
int a[5001];
int p[5000];
long long tr(){
	long long sum=0;
	for(int i=1;i<=4999;i++){
		sum+=p[i];
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
cout<<tr();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(n==3){
		if(a[1]<a[2]+a[3])	cout<<1;
		else				cout<<0;
		return 0;
	}
	if(a[1]=a[n]){
		long long l=0;
		for(int i=3;i<=n;i++){
			l+=C(n,i);
			l=l%998244353;
		}
		cout<<l;
		return 0;
	}
	
	long long sum=0;
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n+1-i;j++){
			int max1=a[j];
			for(int i=1;i<=i-1;i++){
				p[i]=a[j+i];
			} 
		}
	}
}
