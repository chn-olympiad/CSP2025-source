#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<n;i++){
		ans+=i;
	}
	cout<<ans*n;
	return 0;
} 
// 1 2 3 4   1 2 4 3   1 3 2 4   1 3 4 2   1 4 2 3   1 4 3 2
