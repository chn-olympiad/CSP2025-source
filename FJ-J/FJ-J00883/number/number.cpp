#include<bits/stdc++.h>
using namespace std;
int n,t[15];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++) if(s[i]>='0'&&s[i]<='9') t[s[i]-48]++;
	for(int i=9;i>=0;i--) while(t[i]){
		cout<<i;
		t[i]--;
	}
	return 0;
} 
