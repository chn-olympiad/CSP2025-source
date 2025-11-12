#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r=0,c=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	
	sort(a+1,a+m*n+1);
	for(int i=1;i<=m*n;i++){
		if(a[i]==r){
			c=m*n-i+1;
		}
	}	
	int h=c/n;
	if(c%n!=0){
		h++;
	}
	int l=0;
	if(h%2!=0){
		l=(c-1)%n+1;
	}else{
		l=n-((c-1)%n+1)+1;
	}
	cout<<h<<" "<<l;
	return 0; 
} 