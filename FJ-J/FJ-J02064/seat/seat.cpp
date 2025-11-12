#include<bits/stdc++.h>
using namespace std;
long long arr[101],n,m;
bool f(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long s,a;
	for(int i=1;i<=n*m;i++){
		cin>>arr[i];
	}
	s=arr[1];
	sort(arr+1,arr+n*m+1,f);
	
	for(int i=1;i<=n*m;i++){
		if(arr[i]==s){
			a=i;
		}
	}
	long long i,j;
	if(a%n==0){
		i=a/n;
	}
	else{
		i=a/n+1;
	}
	if(i%2==1){
		j=a-(i-1)*m;
	}
	else{
		j=n-(a-(i-1)*m)+1;
	}
	cout<<i<<' '<<j;
	fclose(stdin);
	fclose(stdout);
	return 0;
}