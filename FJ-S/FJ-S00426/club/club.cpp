#include<bits/stdc++.h>
using namespace std;
int n;
void sb(){
	vector<int> a,b,c;
	int x,maxn;
	cin>>x;
	maxn=x/2;
	for(int i=1;i<=x;i++){
		 int a1,a2,a3;cin>>a1>>a2>>a3;a.push_back(a1);}sort(a.begin(),a.end());int ans=0;for(int i=a.size();i>maxn;i--){ans+=a[i];}cout<<ans<<"\n";}int main(){freopen("club.in","r",stdin);freopen("club.out","w",stdout);cin>>n;for(int i=1;i<=n;i++){sb();}}
