//GZ-S00217 贵阳市第三实验中学 李圣清 
#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
vector<long long>c;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		int cc;
		cin>>cc;
		c.push_back(cc);
	}
	long long ans=1;

	for(int i=2;i<=n;i++){
		ans=ans*i;
	}
	cout<<ans<<endl;

	return 0;
}
