#include<bits/stdc++.h>
using namespace std;
void solve();
const int MAXN=1000005;
string st;
int a[MAXN],ans=0;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
    freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
void solve(){
	cin>>st;
	for(int i=0;i<st.size();i++){
		if(st[i]=='0') a[++ans]=0;
		else if(st[i]=='1') a[++ans]=1;
		else if(st[i]=='2') a[++ans]=2;
		else if(st[i]=='3') a[++ans]=3;
		else if(st[i]=='4') a[++ans]=4;
		else if(st[i]=='5') a[++ans]=5;
		else if(st[i]=='6') a[++ans]=6;
		else if(st[i]=='7') a[++ans]=7;
		else if(st[i]=='8') a[++ans]=8;
		else if(st[i]=='9') a[++ans]=9;
	}
	sort(a+1,a+1+ans,cmp);
	for(int i=1;i<=ans;i++) cout<<a[i];
	return ;
}
