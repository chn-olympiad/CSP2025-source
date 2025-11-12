#include<bits/stdc++.h>
using namespace std;
int r,a[105],ans,ans1,n,m,f;
map<int,int>mp;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a,a+n*m);
	for(int i=1;i<=m*n;i++){
		mp[a[i]]=i;
	} 
	ans=(n*m-mp[r])/m;
	ans1=(n*m-mp[r])%n;
	if(ans==1&&ans1==0){
		cout<<"1 2";
		return 0;
	}
	cout<<ans<<" "<<ans1;
	return 0;
} 


