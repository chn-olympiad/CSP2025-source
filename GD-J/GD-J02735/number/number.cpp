#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int ans[N];
int n=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans[++n]=((int)(s[i]-'0'));
		}
	}
	sort(ans+1,ans+n+1,cmp);
	for(int i=1;i<=n;i++)cout<<ans[i];
	return 0;
} 
