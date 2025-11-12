#include<bits/stdc++.h>
using namespace std;
int t;
struct state{
	int a1,a2,a3;
}a[100001];
bool cmp(state x,state y){
	return x.a1>y.a1;
}
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=a[i].a1;
		}
		cout<<ans<<endl;
		ans=0;
	}
	
	return 0;
}

