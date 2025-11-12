#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main (){
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,cnt=0;
		cin>>n;
		int s=n/2;
		for(int i=1;i<=n;i++){
			int s1,s2,s3;
			cin>>s1>>s2>>s3;
			int maxx=max(max(s1,s2),s3);
			cnt+=maxx;
		}
		cout<<cnt<<endl;                                                      
	}
	
	return 0;
} 
