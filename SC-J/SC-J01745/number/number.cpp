#include<bits/stdc++.h>
using namespace std;
string s,ans,anss;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int i=0;
	for(char c:s){
		if(c>='0'&&c<='9'){
			ans+=s[i];
		}
		i++;
	}
	i--;
	sort(ans.begin(),ans.end());
	for(int j=i;j>=0;j--){
		anss+=ans[j];
	}
	cout<<anss;
	return 0;
} 