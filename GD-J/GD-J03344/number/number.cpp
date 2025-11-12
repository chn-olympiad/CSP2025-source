#include<bits/stdc++.h>
using namespace std;
string s;
int a[100009];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}sort(a+1,a+cnt);
	for(int i=cnt-1;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
