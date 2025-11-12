#include<bits/stdc++.h>
using namespace std;
int clen=0;
int ans[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	int clen=0;
	int ans[100005];
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9'){
			ans[clen]=int(str[i]);
			clen++;
		}
	}
	sort(ans,ans+clen);
	for(int i=clen-1;i>=0;i--){
		cout<<char(ans[i]);
	}
	return 0;
}
