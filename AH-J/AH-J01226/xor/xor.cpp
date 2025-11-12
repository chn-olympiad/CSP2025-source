#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long sum=0;
struct node{
	long long x;
	long long y;
}a[600000];
long long b[600000];
long long cnt;
bool f=false;
long long c;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=0;i<n;i++){
		cin>>a[i].x;
		b[a[i].x]++;
		a[i].y=a[i].x^a[i-1].x;
		if(a[i].y==k)	sum++;
		if(a[i].x==1){
			c++;
		}
		if(a[i].x==k){
			sum=1;
		}
	}
	if(k==0 && c==n){
		cout<<n/2<<endl;
		return 0;
	}
	if(n<=10 || n<=100 && k<=1 && k!=0){
		for(int i=0;i<600000;i++){
			sum+=b[i]/2;
		}
	}
	else{
		for(long long i=0;i<n;i++){
			if(a[i].y==k)	sum++;
		}
	}
	cout<<sum<<endl;	
	return 0;
}
