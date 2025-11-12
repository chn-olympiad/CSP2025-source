#include<bits/stdc++.h>
using namespace std;
int t[15];
string max1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')t[s[i]-'0']++;
	}
	int cnt=9;
	while(cnt>=0){
		while(t[cnt]){
			max1+=cnt+'0';
			t[cnt]--;
		}
		cnt--;
	}
	cout<<max1;
	return 0;
} 
