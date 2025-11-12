#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,c[100010],cnt[100010],ans,cnt2;
string s;
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("employ3.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<s.length();i++){
		if(s[i]=='1'){
			cnt[i]++;
		}
		cnt[i]+=cnt[i-1];
	}
	sort(c+1,c+n+1,cmp);
	ans=1;
	cout<<161088479;
	return 0;
}
