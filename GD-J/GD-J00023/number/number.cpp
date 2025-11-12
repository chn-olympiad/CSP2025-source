#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
string s;
int a[N],la;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9') a[++la]=s[i]-'0';
	}
	sort(a+1,a+la+1,cmp);
	for(int i=1;i<=la;i++) cout<<a[i]; 
	return 0;
}
