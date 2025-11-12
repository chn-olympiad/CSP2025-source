#include <bits/stdc++.h>
using namespace std;
#define int long long

string str;
int a[1000005],n,ans;
bool bj=0;

bool cmp(int x,int y){
	return x>y;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>str;
	int len=str.size();
	for(int i=0;i<len;i++){
		if(str[i]<='9'&&str[i]>='0'){
			a[++n]=str[i]-'0';
			if(a[n]!=0)bj=1;
		}
	}
	if(bj==0){
		cout <<0;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		cout <<a[i];
	}
	
	return 0;
}
