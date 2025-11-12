#include<bits/stdc++.h>
using namespace std;
string s;
long long num[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int a=s.size();
	int ni=0;
	for(int i=0;i<a;i++){
		if(s[i]<='9'&&s[i]>='0'){
			num[ni]=s[i]-'0';
			ni++;
		}
	}
	sort(num,num+ni);
	for(int i=ni-1;i>=0;i--){
		cout<<num[i];
	}
	return 0;
} 
