//GZ-S00104 贵阳市南明区双龙华麟学校 周子铠 
#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int s[N],a[N],sum,n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0) sum*=a[i];
	}
	sort(a+1,a+n+1);
	cout<<sum*128;
	return 0;
}
