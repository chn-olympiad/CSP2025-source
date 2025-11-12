#include<bits/stdc++.h>
using namespace std;
struct member{
	int s1,s2,s3;
}a[10001];
bool cmp(member x,member y){
	if(x.s1>y.s1){
		return 1;
	}
}
int n,ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].s1>>a[i].s2>>a[i].s3;
		}
	}
	sort(a+1,a+n+1,cmp);
	int maxn=n/2,ans=0;
	for(int i=1;i<=maxn;i++){
		ans+=a[i].s1;
	}
	cout<<ans;
	return 0;
}