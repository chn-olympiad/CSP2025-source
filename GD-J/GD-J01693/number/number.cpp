#include<bits/stdc++.h>
using namespace std;
int a[1000009];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cnt=0;
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++){
		bool isnum=true;
		if(s[i]<='z'&& s[i]>='a' || s[i]<='Z' && s[i]>='A'){
			isnum=false;
		}
		if(isnum){
			a[cnt]=(int)s[i]-48;
			cnt++;
			}
		}
	sort(a,a+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout << a[i];
	}
	return 0;
}
