#include<bits/stdc++.h>
using namespace std;
int const maxn=1e6+4;
string s;
char num[maxn];
int ans=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for (int i=0;i<=len-1;i++){
		if (s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			num[i]=s[i];
			ans++;
		}
		else num[i]='k';
	} 
	sort(num,num+len);
	for (int i=len-1;i>=0;i--){
		if (num[i]=='k') continue;
		cout<<num[i];
	}
	return 0;
} 

