#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int a[MAXN];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int cnt=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			a[cnt]=1;
			cnt++;
		}
		if(s[i]=='2'){
			a[cnt]=2;
			cnt++;
		}
		if(s[i]=='3'){
			a[cnt]=3;
			cnt++;
		}
		if(s[i]=='4'){
			a[cnt]=4;
			cnt++;
		}
		if(s[i]=='5'){
			a[cnt]=5;
			cnt++;
		}
		if(s[i]=='6'){
			a[cnt]=6;
			cnt++;
		}
		if(s[i]=='7'){
			a[cnt]=7;
			cnt++;
		}
		if(s[i]=='8'){
			a[cnt]=8;
			cnt++;
		}
		if(s[i]=='9'){
			a[cnt]=9;
			cnt++;
		}
		if(s[i]=='0'){
			a[cnt]=0;
			cnt++;
		}
	}
	sort(a,a+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout<<a[i];
	} 
	return 0;
} 