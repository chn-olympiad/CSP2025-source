#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int t,a,b,c,ans;
int cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ans=0;
		while(n--){
			cin>>a>>b>>c;
			ans+=max(max(a,b),max(b,c));
		}
		cout<<ans<<endl;
	}
	return 0;
}
