#include <bits/stdc++.h>
using namespace std;
int a[107];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	int w;
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			w=i;
			break;
		}
	}
	int ja=w/n+1;
	if(w%n==0){
		ja=w/n;
	}
	else ja=w/n+1;
	int mx=ja*n;
	if(ja%2==1){
		cout<<ja<<" "<<n-(mx-w);
	}
	else{
		cout<<ja<<" "<<mx-w+1;
	}
	return 0;
} 
