#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
void solve(){
	string s;
	cin>>s;
	int cnt=0,len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9')
			a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
		cout<<a[i];
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	//freopen("number.in","w",stdin);
	//freopen("number.out","r",stdout);	
	//Never gonna give you up.Never gonna let you down
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int QwQawaqaq=1;
	while(QwQawaqaq--)
		solve();
	return 0;
}
