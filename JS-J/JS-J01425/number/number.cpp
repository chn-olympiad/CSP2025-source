#include <bits/stdc++.h>
using namespace std;
int arra[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int lens=s.size(),cnt=1;
	for(int i=0;i<lens;i++){
		if(s[i]>='0'&&s[i]<='9'){
			arra[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(arra+1,arra+cnt,greater<int>());
	for(int i=1;i<=cnt-1;i++){
		cout<<arra[i];
	}
	return 0;
}