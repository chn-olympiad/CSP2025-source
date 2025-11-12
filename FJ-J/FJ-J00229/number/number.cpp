#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005],ans=0,cnt=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=1000005;i++) a[i]=-1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-48;
			cnt++;
		}
	}
	sort(a,a+1000005,cmp);
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	return 0;
}
