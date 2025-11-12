#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000010];
int main(){
	freopen(".in","r",stdin); 
	freopen(".out","w",stdout);
	cin>>s;
	int cnt=0;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			cnt++;
			num[cnt]=s[i]-'0';
		}
	}
	sort(num+1,num+1+cnt);
	for(int i=cnt;i>0;i--){
		cout<<num[i]; 
	}
	return 0;
} 
