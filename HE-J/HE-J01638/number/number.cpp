#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll num[1000002],lennum=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string s;
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			num[lennum]=s[i]-'0';
			lennum++;
		}
	}
	sort(num,num+lennum);
	for(ll i=lennum-1;i>=0;i--){
		cout<<num[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
