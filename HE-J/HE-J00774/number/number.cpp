#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[10000];
	int u=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[u]=s[i]-48;
			u++;
		}
	}
	for(int i=0;i<u;i++){
		sort(a,a+u+1);
	}
	for(int i=u;i>0;i--){
		cout<<a[i];
	}
	return 0;
}
