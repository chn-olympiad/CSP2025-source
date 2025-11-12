#include<bits/stdc++.h>
using namespace std;
string s;
long long b[15];
int c[1000005],cc=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	long long len=s.size()-1;
	for(int i=0;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(b[i]>0){
			c[++cc]=i;
			b[i]--;
		}
	}
	if(c[1]==0) cout<<"0\n";
	else{
		for(int i=1;i<=cc;i++){
			cout<<c[i];
		}
		cout<<"\n";
	}
	return 0;
}
