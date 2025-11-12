#include<bits/stdc++.h>
using namespace std;
int m,n,s[1000],w[1000],s0=0;
string a;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>a;
	sort(s+1,s+n+1);
	int t=1;
	for(int i=0;i<a.size();i++){
		if(a[i]=='0'){
			s0++;
		}
		else break;
	}
	int ans1=1;
	for(int i=n;i>n-s0;i--){
		ans1*=i;
	}
	int ans2=1;
	for(int i=1;i<=m;i++){
		ans2*=i;
	}
	cout<<ans1/ans2;
	return 0;
}
