#include<bits/stdc++.h>
using namespace std;
#define int long long
char a[1000005];
int b[1000005];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>a;
/*	int xx=a[0];
	cout<<xx;
	return 0;*/
	int c=0,i=0;
	while(a[i]){
		if(a[i]>='0'&&a[i]<='9'){
			b[++c]=a[i]-48;
		}
		i++;
	}
	sort(b+1,b+1+c);
	if(b[c]==0){
		cout<<0;
		return 0;
	}
	for(int i=c;i>=1;i--){
		cout<<b[i];
	}
	return 0;
}
