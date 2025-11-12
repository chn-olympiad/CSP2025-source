#include<bits/stdc++.h>	
#define endl '\n'
#define ll long long
using namespace std;
const int N=1e6+2;
string s;
int a[N],cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		char c=s[i];
		if(c>='0' && c<='9'){
			a[++cnt]=c-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}
/*
吾日三省吾身：
freopen取消注释了乎？
文件名写对了乎？
样例过了乎？
*/