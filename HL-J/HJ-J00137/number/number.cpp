#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10;
int a[N];
bool bijiao(int a,int b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int indx=1;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[indx++] = s[i]-'0';
		}
	}
	sort(a+1,a+indx,bijiao);
	for(int i=1;i<indx;i++){
		cout << a[i];
	}	
	return 0;
}
