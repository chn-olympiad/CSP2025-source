#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6+50;
char a[N];
int cnt;
int p[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>(a+1);
	int n=strlen(a+1);
	for(int i=1;i<=n;i++) {
		if(a[i]>='0'&&a[i]<='9') p[++cnt]=a[i]-'0';
	}
	random_shuffle(p+1,p+cnt+1);
	sort(p+1,p+cnt+1,[](int x,int y){return x>y;});
	for(int i=1;i<=cnt;i++) {
		cout<<p[i];
	}
	return 0;
}