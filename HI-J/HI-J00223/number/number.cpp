#include<bits/stdc++.h>
using namespace std;
string s;
int maxn=-1;
int a[1000007],n;
priority_queue<int> q; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	int base=1;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			n++;
			a[base]=s[i]-'0';
			maxn=max(maxn,s[i]-'0');
			base++;
		}
	}
	sort(a+1,a+n+1);
	if(maxn==0){
		cout<<0;
		return 0;
	}
	for(int i=n;i>=1;i--) cout<<a[i];
	return 0;
}
