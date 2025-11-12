#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
void solve(){
	str a;
	ll num[10]={};
	cin>>a;
	for(int i=0;i<=a.size();i++)if(a[i]>='0'&&a[i]<='9')num[a[i]-'0']++;
	for(int i=9;i>=0;i--){
		while(num[i]){
			printf("%lld",i);
			num[i]--;
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

