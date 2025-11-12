#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char ch;
int ans[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int cnt=0;
	while(cin>>ch)
		if(ch>='0'&&ch<='9') ans[cnt++]=ch-'0';
	sort(ans,ans+cnt,cmp);
	for(int i=0;i<cnt;i++) cout<<ans[i];
	return 0;
} 
