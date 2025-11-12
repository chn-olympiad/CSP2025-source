#include <bits/stdc++.h>
using namespace std;
char a[1000005];
int t[103],ans=0,n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	char c;
	while(cin>>c)a[++n]=c;
	for(int i=1;i<=n;i++){
		char c=a[i];
		if(c>='0'&&c<='9')t[c-'0']++,ans++;
	}
	
	for(int i=9;i>=0;i--){
		while(t[i]--&&t[i]>=0){
			cout<<i;
		}
	}
	return 0;
}
