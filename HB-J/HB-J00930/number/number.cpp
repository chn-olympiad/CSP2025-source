#include <bits/stdc++.h>
using namespace std;
string a;

int n[105];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int m=a.size();
	memset(n,-1,sizeof n);
	for(int i=0;i<m;i++){
		if('0'<=a[i]&&a[i]<='9') n[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<=n[i];j++){
			cout<<i;
		}
	}
	return 0;
}
