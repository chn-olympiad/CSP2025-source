#include<bits/stdc++.h>
using namespace std;
int n,cnt,b[1000010];
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=a.length();
	a=' '+a;
	for(int i=1;i<=n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[++cnt]=(int)a[i]-'0';
		}
	}
	sort(b+1,b+1+cnt);
	for(int i=cnt;i>=1;i--){
		cout<<b[i];
	}
	return 0;
}