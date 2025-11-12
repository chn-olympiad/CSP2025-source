#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char s[N];
int a[N],m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s+1;
	int n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++m]=s[i]-'0';
		}
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++) cout<<a[i];
	return 0;
}

