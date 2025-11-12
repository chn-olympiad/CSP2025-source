#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=1;
	cin>>t;
	while(t--){
		int n,x,y,z;
		cin>>n;
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>x>>y>>z;
			sum+=x;
		}
		
		cout<<sum<<endl;
		
	} 
	return 0;
	
} 
