#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int num[N+10];
int p;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[p] = s[i]-'0';
			p++;
		}
	}
	sort(num,num+p);
	for(int i=p-1;i>=0;i--){
		cout<<num[i];
	}
	return 0;
}
