#include<algorithm>
#include<iostream>
using namespace std;
int cnt,i,n[1000000];
string s;
bool cmp(int n1,int n2){
	return n1>n2;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')n[cnt++]=s[i]-'0';
	}
	sort(n,cnt+n,cmp);
	for(i=0;i<cnt;i++)cout<<n[i];
	return 0;
}
