#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		int x=int(s[i]-'0');
		if(x>=0&&x<=9){
			a[cnt]=x;
			cnt++;
		}
	}
	sort(a,a+cnt-1,greater<int>());
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	return 0;
}
