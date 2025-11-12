#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e7+100;
char a[N];
ll ans=0;
ll num[N];
int cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;a[i]!=0;i++){
		if(a[i]>='0' && a[i]<='9') {num[++cnt]=a[i]-'0';}
	}
	sort(num+1,num+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<num[i];
	}
	return 0;
}
