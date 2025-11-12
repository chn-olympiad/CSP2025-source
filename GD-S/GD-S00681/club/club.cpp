#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,num=0;
		cin>>n;
		for(int l=0;l<n;l++){
			int a,b,c;
			cin>>a>>b>>c;
			if(a>b&&a>c) num+=a;
			else if(b>a&&b>c) num+=b;
			else num+=c;
		}
		cout<<num<<endl;
	} 
	return 0;
} 
