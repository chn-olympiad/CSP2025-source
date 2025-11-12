#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int s[101];
int s1[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}	
	int mys=s[1],k=0;
	sort(s+1,s+n*m+1);
	for(int i=1;i<=n*m/2;i++){
		swap(s[i],s[n*m-i+1]);
	}
	for(int i=1;i<=n*m;i++){
		if(s[i]==mys){
			k=i;
			break;
		}
//		cout<<s[i]<<" ";
	}	
//	cout<<endl<<mys;
//	cout<<k<<endl;
	int h=k%(2*n);
	if(h>n){
		h=2*n+1-h;
	}else if(h==0){
		h=1;
	}
	int l=k/n;
	if(k%n!=0){
		l++;
	}
	cout<<l<<" "<<h;
	
	return 0;
} 
