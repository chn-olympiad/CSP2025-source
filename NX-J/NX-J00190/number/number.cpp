#include<bits/stdc++.h>
using namespace std;
int num[1000100];
int k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)if(s[i]>='0'&&s[i]<='9'){
		k++;
		num[k]=s[i]-'0';
	}
	sort(num+1,num+1+k,greater<int>());
	for(int i=1;i<=k;i++)cout<<num[i];
	return 0;
}
