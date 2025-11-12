#include<bits/stdc++.h>
using namespace std;
int a[100005],b,c,ans,maxnum,n,t;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		maxnum=n/2;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b>>c;
		}
		sort(a,a+n,cmp);
		for(int i=0;i<maxnum;i++){
			ans+=a[i];
		}
		cout<<ans;
	}
	return 0;
}
