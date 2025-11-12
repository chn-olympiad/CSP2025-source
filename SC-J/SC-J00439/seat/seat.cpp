#include<bits/stdc++.h>
using namespace std;
int a[10010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s=0;
	cin>>s;
	a[1]=s;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int v=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			v=i;
			break;
		}
	}
	int t=v/n;
	if(v%n!=0){
		t+=1;
		cout<<v/n+1;
	}else{
		cout<<v/n;
	}
	cout<<" ";
	if(t%2==0){
		cout<<n-v%n+1;
	}else{
		if(v%n==0){
			cout<<n;
		}else{
			cout<<v%n;
		}
	}
	return 0;
}