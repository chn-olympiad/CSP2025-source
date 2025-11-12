#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
string s;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	int cnt=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+n+1,cmp); 
	for(int i=1;i<=cnt;i++) cout<<a[i];
	return 0;
}
