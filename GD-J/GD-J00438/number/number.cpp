#include<bits/stdc++.h>
using namespace std;
string s;int cnt,ans[12];bool f;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans[int(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<ans[i];j++){
			if(f==0&&i==0)break;
			cout<<i;f=1;
		}
	}
	if(!f)cout<<0;
	return 0;
}
