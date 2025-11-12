#include<bits/stdc++.h>
using namespace std;
int a[10];
bool flag=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			if(!flag&&i>0){
				flag=1;
			}
			if(flag)cout<<i;
			a[i]--;
		}
	}
	if(!flag)cout<<0<<'\n';
	return 0;
}
