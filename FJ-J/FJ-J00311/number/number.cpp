#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
string a;
int b[N];
bool cmp(int x,int y){
	return x>=y;
}
int main(){
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a;
	int len=a.length();
	int cnt=0;
	for(int i=0;i<len;i++){
		if(a[i]>='0' && a[i]<='9') b[++cnt]=a[i]-'0';
	}
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=cnt;i++) cout<<b[i];
	return 0;
}
