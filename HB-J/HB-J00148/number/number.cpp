#include<bits/stdc++.h>
using namespace std;
int a[1000006];
int prs;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<=int(s.length()-1);i++){
		if(s[i]>='0'&&s[i]<='9'){
			prs++;
			a[prs]=int(s[i]-'0');
		}	
	}
	sort(a+1,a+1+prs);
	for(int j=prs;j>=1;j--){
		cout<<a[j];
	}
	return 0;
}
