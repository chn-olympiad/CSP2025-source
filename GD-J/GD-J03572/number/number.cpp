#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
string s;
ll cnt,a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=(ll)s[i]-'0';
		} 
	}
	sort(a+1,a+1+cnt);
	if(a[cnt]==0){
		cout<<0;
		return 0;
	}
	for(int i=cnt;i>=1;i--) cout<<a[i];
	return 0;
}
