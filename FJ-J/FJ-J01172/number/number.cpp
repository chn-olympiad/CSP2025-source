#include<bits/stdc++.h>
using namespace std;
int n,t[11];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	memset(t,0,sizeof(t));
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[int(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(t[i]!=0){
			for(int j=1;j<=t[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
