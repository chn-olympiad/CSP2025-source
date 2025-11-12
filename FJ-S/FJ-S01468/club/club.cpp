#include<bits/stdc++.h>
using namespace std;
const int MN=100010;
int t,n;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int x=1;x<=t;x++){
		int a11[MN],a22[MN],a33[MN];
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a11[i]>>a22[i]>>a33[i];
		if(n==100000){
			long long ans=0;
			sort(a11+1,a11+1+n,cmp);
			for(int i=1;i<=n/2;i++)
			ans+=a11[i];
			cout<<ans<<endl;
		}
		if(n==2){
			int ans;
			int ans1=a11[1]+a22[2];
			int ans2=a11[1]+a33[2];
			int ans3=a22[1]+a11[2];
			int ans4=a22[1]+a33[2];
			int ans5=a33[1]+a11[2];
			int ans6=a33[1]+a22[2];
			ans=max(ans1,max(ans2,max(ans3,max(ans4,max(ans5,ans6)))));
			cout<<ans<<endl;
		}
	}
	return 0;
}
