#include<bits/stdc++.h>
using namespace std;
int a[10000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int u=1;
	string s;
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[u]=s[i]-'0';
			u++;
		}
		sort(a+1,a-u);
		for(int i=u;i>=0;i--){
		cout<<a[i]; 
		}
	}
	return 0;
}
