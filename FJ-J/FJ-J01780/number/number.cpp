#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+100;
string s;
int a[N],num=1;
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[num]=s[i]-'0';
			num++;
		}
	}
	sort(a+1,a+num);
	for(int i=num-1;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
