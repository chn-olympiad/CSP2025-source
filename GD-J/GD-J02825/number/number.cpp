#include <bits/stdc++.h>
using namespace std;
#define For(i,x,y) for(int i=x;i<=y;i++)
#define ll long long
const int M=1000101;
const int inf=1e9+7;
int b[M],cnt;
string a;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	For(i,1,a.size()){
		if(a[i-1]>='0'&&a[i-1]<='9'){
			b[++cnt]=a[i-1]-'0';
		}
	}
	sort(b+1,b+1+cnt,cmp);
	For(i,1,cnt) printf("%d",b[i]);
	return 0;
}
