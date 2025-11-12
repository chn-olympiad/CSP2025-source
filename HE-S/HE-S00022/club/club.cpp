#include <bits/stdc++.h>
using namespace std;
int t;
int n,ans=0,a[100005][3];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t!=0){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	for(int i=0;i<n;i++){
		ans+=max(a[i][0],max(a[i][1],a[i][2]));
	}
	cout<<ans;
	t--;
	}
	return 0;
}
