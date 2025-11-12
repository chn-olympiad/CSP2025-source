#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char c;
int a[N],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c){
		if(c>='0'&&c<='9') a[++cnt]=c-'0';
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--) cout<<a[i];
	return 0;
}
