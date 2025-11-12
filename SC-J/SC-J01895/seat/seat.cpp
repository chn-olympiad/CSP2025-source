#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],r,nm;
bool cmp(int c,int m){
	return (c>m);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	int l=n*m;
	a[1]=r;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+l+1,cmp);
	for(int k=1;k<=l;k++){
		if(a[k]==r) {
			nm=k;
			break;
		}
	}
	if(nm%n==0) cout<<nm/n<<" ";
	else cout<<nm/n+1<<" ";	
	
	if(nm%n==0) cout<<n;
	else
	{
		if((nm/n)%2==0){
			cout<<nm%n;
		}else if((nm%n)==1){
			cout<<n;
		}else{
			cout<<n-(nm%n);
		}
	}
}