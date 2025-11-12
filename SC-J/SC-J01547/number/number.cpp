#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s,ans="";
	cin>>s;
	int l=s.size(),len=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans+=s[i];len++;
		}
	}
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
	cout<<ans;
	
	return 0;
}