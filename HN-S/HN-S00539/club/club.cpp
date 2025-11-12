#include<bits/stdc++.h>
using namespace std;
int n,l,s[4],ant;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>l;
	for(int p=0;p<l;++p){
		cin>>n;
		ans=0;
		int a[n][3];
		for(int i=0;i<n;++i){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			ans+=max(a[i][0],max(a[i][1],a[i][2]));
		}
		cout<<ans<<"\n";
	}
	return 0;
}
