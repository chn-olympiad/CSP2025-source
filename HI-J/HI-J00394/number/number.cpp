#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int cnt,cnt_2;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;){
		if(a[i]==0){
			i--;
			continue;
		}
		if(cnt_2==0&&i==0){
			cout<<0;
			return 0;
		}
		cout<<i;
		cnt_2++;
		a[i]--;
	}
	return 0;
} 
