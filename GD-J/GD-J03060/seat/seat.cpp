#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m; 
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1],r;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(a[i]==R){
			r=i;
		}
	}
	int l=r/n;
	if(r%n==0){
		cout<<l;
	}else{
		cout<<l+1;
	}
	cout<<" ";
	if(l%2){
		cout<<n-r%n;
	}else{
		cout<<r%n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
