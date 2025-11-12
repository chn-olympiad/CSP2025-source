//RP++
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N]; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=0;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt);
	if(a[cnt]==0) {
		cout<<0;
		return 0;
	}
	for(int i=cnt;i>=1;i--) cout<<a[i];
	return 0;
}