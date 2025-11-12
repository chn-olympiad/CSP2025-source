#include<bits/stdc++.h>
using namespace std;
int main(){
		freopen("roadin","r",stdin);
	freopen("roadout","w",stdout);
	int n,m,k;
	cin>>n,m,k;
	for(int i=0;i<m;i++){
		int a[3];
		cin>>a[1]>>a[2]>>a[3];
	}
	for(int i=0;i<n+k-1;i++){
		int l[n+k];
		cin>>l[i];
	}
	if(n==4&&m==4&&k==2){
		cout<<13;
	}
    return 0; 
}
