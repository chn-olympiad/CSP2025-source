#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+1];
	cin>>a[1];
	int ans=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n*m+1);
	
	int mas;
	for(int i=n*m;i>0;i--){
		if(a[i]==ans){
			mas=(n*m-i+1);
			break;
		}
	
	}

	int l;
	
	l=(mas/n);	
	if((mas-l*n)>0)	{
		l++;
	}
	cout<<l<<' ';
	int hang;
	if(l%2==0){
		hang=(n+1-mas%n);
	}else{
		hang=mas%n;
	}
	if(hang>m)hang-=n;
	cout<<hang;
	return 0;
}