#include <bits/stdc++.h>
using namespace std;
string a;
int x[1000010];
int cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int la=a.length();
	for(int i=0;i<la;i++){
		if(a[i]>='0' && a[i]<='9') x[++cnt]=(a[i]-'0'); 
	}
	sort(x+1,x+cnt+1);
	for(int i=cnt;i>=1;i--) cout<<x[i];
	return 0;
}

