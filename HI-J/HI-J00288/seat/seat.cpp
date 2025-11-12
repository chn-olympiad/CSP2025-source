#include<bits/stdc++.h>
using namespace std;
int n,m,a[1111],w,s,p,l;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	w=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==w) s=i;
	}
	if(s%n!=0){
		cout<<s/n+1<<" ";
		p=s/n+1;
	} 
	else{
		cout<<s/n<<" ";
		p=s/n;
	}
	l=s%n;
	if(p%2==1){
	if(l==0){
		cout<<n;
	}
	else cout<<l;
 	}
 	else{
	if(l==0){
		cout<<1;
	}
	else cout<<n-l+1;
}
	return 0;
} 
