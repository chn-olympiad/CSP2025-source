#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int sum;
int b;
bool cmp(int x, int y){
	return x>y;
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>> n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	b=a[1];
	for(int i=1;i<=n;i++){
		sum=sum+a[i];
	}
	if(sum>2*b){
		
		cout<<1;
	}
	
	return 0;
}
