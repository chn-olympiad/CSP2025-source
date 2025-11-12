#include<bits/stdc++.h>
#define int long long
using namespace std;
char a[1000010];
int r[1000010];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>(a+1);
	int n=strlen(a+1);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if('0'<=a[i]&&a[i]<='9'){
			r[++cnt]=a[i]-'0';
		}
	}
	sort(r+1,r+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<r[i];
	}
	cout<<endl;
	return 0;
}
