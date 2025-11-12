#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,a[100005][5]={0};
		long long cnt=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=n;i++)cnt+=max(max(a[i][1],a[i][2]),a[i][3]);
		cout<<cnt<<"\n"; 
	}
	return 0;
} 
