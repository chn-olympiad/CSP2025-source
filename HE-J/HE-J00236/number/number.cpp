#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int a[N],cnt=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			cnt++;
			a[cnt]=int(s[i]-'0');
		}
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
