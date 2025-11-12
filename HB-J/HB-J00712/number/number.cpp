#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001],len,sl;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	sl=s.size();
	for(int i=0;i<sl;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++len]=s[i]-'0';
		}
	}sort(a+1,a+len+1);
	for(int i=len;i>=1;i--)cout<<a[i];
	return 0;
}
	
