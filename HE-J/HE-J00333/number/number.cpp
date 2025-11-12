#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
const int N=1e6+47;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
string ans;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>s;
	int l=s.size();
	int cnt=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=s[i]-'0';
		}
	}
//	for(int i=1;i<=cnt;i++)cout<<a[i]<<" ";
//	cout<<"\n";
	sort(a+1,a+1+cnt,cmp);
//	for(int i=1;i<=cnt;i++)cout<<a[i]<<" ";
//	cout<<"\n";
	for(int i=1;i<=cnt;i++){
		ans+=a[i]+'0';
	}
	cout<<ans;
	return 0;
}
