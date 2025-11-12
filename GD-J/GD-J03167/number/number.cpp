#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[s.size()+5];
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	int res=0;
	sort(a,a+cnt);
	for(int i=cnt;i>=0;i--){
		res=res*10+a[i];
	}
	cout<<res;
	return 0;
}
