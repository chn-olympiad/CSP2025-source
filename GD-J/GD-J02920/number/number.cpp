#include<iostream>
#include<cstdio>
#include<iomanip>
#include<math.h>
#include<queue>
#include<stack>
#include<map>
#include<cstring>
#include<vector>
#include<algorithm>
#define LL long long
const int N=1e5+10;
const int Inf=0x3f3f3f3f;
using namespace std;
string s;//,ans;
LL ans[N],a;
bool cmd(LL a,LL b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans[++a]=s[i]-'0';
		}
	}
	sort(ans+1,ans+a+1,cmd);
	for(int i=1;i<=a;i++){
		cout<<ans[i];
	}
}
