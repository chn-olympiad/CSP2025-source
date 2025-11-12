#include<bits/stdc++.h>
#define N int(1e6+6)
using namespace std;
char s[N];
int a[N];
int f[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int maxn=-1;
	for(int i=0;i<strlen(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			int x=s[i]-'0';
			f[x]++;
			maxn=max(maxn,x);
		}
	}
	for(int i=maxn;i>=0;i--){
		while(f[i]){
			cout<<i;
			f[i]--;
		}
	}
	return 0;
}
