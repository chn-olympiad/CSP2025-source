#include<bits/stdc++.h>
#define ll long long
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout);
using namespace std;
const int N=1e6+5;
string s;
int a[N],cnt;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	fre("number");
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	for(char c:s){
		if(c>='0'&&c<='9')a[cnt++]=c-'0';
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++)cout<<a[i];
	cout<<"\n";
	return 0;
}