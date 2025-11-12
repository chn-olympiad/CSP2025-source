#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[100];
bool flag=0;
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0' && s[i]<='9') cnt[s[i]-'0']++;
	for(int i=9;i>=0;i--){
		if(i || flag)
			while(cnt[i]){
				cnt[i]--;
				cout<<i;
				flag=1;
			}
		if(i==0 && flag==0 && cnt[i]!=0) cout<<0;
	}
	
	return 0;
} 
