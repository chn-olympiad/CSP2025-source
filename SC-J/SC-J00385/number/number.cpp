#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
string s;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>s;
    int cnt=0;
    for(int i=0;i<s.size();i++){
    	if(s[i]<='9' && s[i]>='0'){
    		a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}