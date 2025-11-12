#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int k=0;
	for(int i=1;i<=n*m;++i){
		if(a[i]==r){
			k=i;
			break;
		}
	}
	cout<<k/n+(k%n>0)<<" ";
	if((k/n+(k%n>0))%2==1){
		if(k%n>0)
		cout<<k%n;
		else cout<<n;
	}
	else{
		if(k%n>0){
			cout<<n-k%n+1;
		}
		else cout<<1;
	} 
	return 0;
}


