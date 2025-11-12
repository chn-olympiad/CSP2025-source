#include<bits/stdc++.h>
using namespace std;
string a;char b[1000005];int cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<int(a.size());i++){
		if(a[i]>='0' && a[i]<='9') b[++cnt]=a[i];
	}
	sort(b+1,b+1+cnt);
	for(int i=cnt;i>0;i--) printf("%c",b[i]);
	return 0;
} 
