#include <bits/stdc++.h>
using namespace std;
int main(){
///freopen("club.in","r","stdin");
///freopen("club.out","w","stdout");
	int t,n,sum=0;
	cin>>t>>n;
	for(int i=0;i<=n;i++){
		if(t<=n/2)
		sum+=t;
	}
	cout<<sum<<endl;	
}				

