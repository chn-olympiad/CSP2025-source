#include<bits/stdc++.h>
using namespace std;
string a;int cnt=1;int ans[10000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0' && a[i]<='9'){
			ans[cnt]=int(a[i]-'0'+0);
			cnt++;
		}
	}
	cnt--;
	sort(ans+1,ans+1+cnt);
	for(int i=cnt;i>=1;i--)cout<<ans[i];
	return 0;
} 
