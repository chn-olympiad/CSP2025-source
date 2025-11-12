#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll a[1000005],cnt=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<cnt;i++) cout<<a[i];
}
