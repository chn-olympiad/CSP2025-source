#include<bits/stdc++.h>
using namespace std;
int a[5001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	for(int i=0;i<=n-1;i++){
		cin>>a[i];
	}
	int s=0;
	sort(a,a+n,cmp);
	for(int i=1;i<=n-1;i++){
		s+=a[i];
	}
	if(n==3&&s>2*a[0]){
		cout<<1;
		return 0
	}
	if(a<3){
		cout<<0;
		return 0;
	}
	return 0;
}
