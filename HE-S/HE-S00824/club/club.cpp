#include<bits/stdc++.h>
using namespace std;
long long z;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		z=0;
		int n;
		cin>>n;
		int a,b,c;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			z+=max(a,max(b,c));
		}
		cout<<z<<endl;
	}
	return 0; 
} 
