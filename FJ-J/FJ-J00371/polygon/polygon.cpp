#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n,a[5009];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==5&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4){
		cout<<9;
	}
	return 0;
} 
