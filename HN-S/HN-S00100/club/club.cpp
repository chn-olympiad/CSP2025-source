#include<bits/stdc++.h>
using namespace std;
long long n,t,c1,c2,c3,ans;
struct A{
	int a1,a2,a3,flag=0;
}s[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=0;i<n;++i){
			cin >> s[i].a1 >> s[i].a2 >> s[i].a3;
			ans+=max(s[i].a1,max(s[i].a2,s[i].a3));
		}
	}
	cout << ans;
	return 0;
}
