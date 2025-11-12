#include<bits/stdc++.h>
using namespace std;
const int N=1e8+7;
long long a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long cnt=0;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			a[++cnt]=int(s[i]-'0');
		}
	}
	sort(a+1,a+1+cnt);
	for(long long i=cnt;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}


