#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
char c[maxn];
//char c1[maxn];
int cnt;
int a[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	cin>>c;
	for(int i=0;i<(int)strlen(c);++i){
		if(c[i]>='0'&&c[i]<='9'){
			a[++cnt]=c[i]-'0';
		
		}
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;--i){
		printf("%d",a[i]);
	}
	return 0;
}