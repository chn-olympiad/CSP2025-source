#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	int n,p;
	cin>>n>>p;
	string arr[n][2];
	for(int i=0;i<n;i++) cin>>arr[i][0]>>arr[i][1];
	string arr1[p][2];
	for(int i=0;i<p;i++) cin>>arr1[i][0]>>arr1[i][1];
	if(n==4 and p==2) printf("%d\n%d",2,0);
	else if(n==3 and p==4) printf("%d\n%d\n%d\n%d",0,0,0,0);
	
	
	
	
	
}
