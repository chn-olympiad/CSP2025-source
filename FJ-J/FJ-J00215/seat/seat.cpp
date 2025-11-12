#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int R;
	for(int i=1;i<=m*n;++i){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+m*n+1);
	for(int i=m*n;i>=1;--i){
		if(a[i]==R){
			R=m*n-i+1;
		}
	}
	int c=1,r=0;
	for(int i=1;i<=R;++i){
		if(c&1){
			if(r==n){
				c++;
			}else{
				r++;
			}
		}else{
			if(r==1){
				c++;
			}else{
				r--;
			}
		}
	}
	cout<<c<<" "<<r; 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
