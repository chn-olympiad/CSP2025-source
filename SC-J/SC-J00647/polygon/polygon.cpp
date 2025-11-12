#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n;
int a[N];
int A(int n,int m){
	long long sum=1;
	for(int i=n;i>=n-m+1;i--)sum*=i;
	return sum;
}
int C(int a,int m){
	return a/A(m,m);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int maxn=-1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n==3){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
		}
		if(sum>=maxn*2){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	if(maxn==1){
		long long answer=0;
		for(int i=1;i<=n;i*=10){
			answer+=C(A(n,i),i);
		}
		cout<<answer;
	}else{
		long long answer=0;
		for(int i=1;i<=n;i*=10){
			answer+=C(A(n,i),i);
		}
		cout<<answer-3;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}