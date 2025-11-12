#include<bits/stdc++.h>
#define ll long long
#define N 15
using namespace std;
string s,ans;
ll p[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') p[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(i==0&&ans==""){cout<<0;return 0;}
		for(int j=1;j<=p[i];j++) ans+=char(i+'0');
	}
	cout<<ans;
	return 0;
}
