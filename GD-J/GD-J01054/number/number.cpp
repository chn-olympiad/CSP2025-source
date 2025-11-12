#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int a[N];
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	int idx=0;
	for(int i=0;i<len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			idx++;
			a[idx]=s[i]-'0';
		}
	}
	sort(a+1,a+1+idx);
	for(int i=idx;i>=1;i--){
		cout<<a[i];
	} 
	return 0;
} 
