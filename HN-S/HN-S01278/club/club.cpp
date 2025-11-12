#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct st{
	int s1,s2,s3;
};
st t[100005],t1[100005],t2[100005],t3[100005];
cmp(int n){
	int c1,c2,c3;
	for(int i=1;i<=n;i++){
		int maxx=max({t[i].s1,t[i].s2,t[i].s3});
		if(t[i].s1)
	}
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cout.tie();
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>t[i].s1>>t[i].s2>>t[i].s3;
		}
		cmp(n);
	}
}

