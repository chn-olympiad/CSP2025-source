#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a,a+cnt,cmp);
	string ans;
	for(int i=0;i<cnt;i++){
		ans+=a[i]+'0';
	}
	cout<<ans;
	return 0;
}
