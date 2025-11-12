#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,sum=0;
		cin>>n;
		int a[n+1][4],b[n+1];
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i]=max(a[i][1],max(a[i][2],a[i][3])); 
		}
		for(int i=1;i<=n;i++){
			sum+=b[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}
