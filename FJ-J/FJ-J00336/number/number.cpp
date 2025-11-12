#include<iostream>
#include<cstring>
#include<algorithm>
//8:42 OK
//Ô¤¼Æ100·Ö 
using namespace std;
typedef long long ll;
const int N = 1e6+10;
string s;
int n,a[N],cnt=0;
bool cmp(int a,int b){
	return a>b; 
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(isdigit(s[i]))a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)cout<<a[i];
	return 0;
}
