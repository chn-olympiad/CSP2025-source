#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e6+10;
string s,a[N];
int cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt++]=s[i];
		}
	}
	sort(a,a+cnt);
	for(int i=cnt;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
