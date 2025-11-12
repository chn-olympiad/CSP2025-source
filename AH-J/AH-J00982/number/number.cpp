#include<bits/stdc++.h>
using namespace std;
char c[1000005];
long long a[1000005],s[15],i,j,n;
bool flag;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> c;
	n = strlen(c);
	for(i=0;i<n;i++){
		if(c[i] >= '0' && c[i] <= '9'){
			s[c[i]-'0']++;
		}
	}
	for(i=9;i>0;i--){
		if(i > 0 && s[i] > 0)flag = true;
		for(j=1;j<=s[i];j++)cout << i;
	}
	if(flag){
		for(i=1;i<=s[0];i++)cout << 0;
	}
	else cout << 0;
	return 0;
}
