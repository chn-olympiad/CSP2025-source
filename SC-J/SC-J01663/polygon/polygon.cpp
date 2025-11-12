#include <bits/stdc++.h>
using namespace std;
long long n,a[100050],maxx=-1,flag=0;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
	}
	if(n==0){
		cout<<0;
		return 0;
	}else if(n==1){
		cout<<0;
		return 0;
	}else if(n==2){
		cout<<0;
		return 0;
	}else if(n==3){
		sort(a+1,a+4,cmp);
		if(a[1]+a[2]>=a[3]){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[1]){
		flag=1; 
		}
	} 
	if(flag==0&&n>3){
		cout<<(n-1)*(n-2)/2;
		return 0;
	}
	//2025csp-j:221;
	return 0;
} 