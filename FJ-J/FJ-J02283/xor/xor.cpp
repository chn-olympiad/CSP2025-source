#include<bits/stdc++.h>
using namespace std;

int n,b[500005],ans;
long long a[500005],k;

void run(){
	for(int i=0;i<n;++i){
		long long tem=a[i];
		int j=i+1;
		while(tem!=k&&j!=n+1){
			tem^=a[j];
			++j;
		}
		if(j==n+1) continue;
		b[i]=j-i;
	}
	int l=INT_MAX;
	for(int i=n-1;i>=0;--i){
		if(b[i]!=0&&i+b[i]-1<l){
			++ans;
			l=i;
		}
	}
	return;
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	run();
	cout<<ans;
}
