#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,inf=0x3f3f3f3f;
typedef long long ll;
int num[N];
bool cmp(int a,int b){
    return a>b;
}
int main(){
	string s;
	cin>>s;
	int len=1;
	for(int i=0;i<s.size();i++)
		if(s[i]<='9' and s[i]>='0')
			num[len++]=s[i]-'0';
    sort(num+1,num+1+len,cmp);
	for(int i=1;i<len;i++)cout<<num[i];
	return 0;
}
