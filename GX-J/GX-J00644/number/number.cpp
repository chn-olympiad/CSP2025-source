#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string a;
int b[N],sw;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[sw]=b[sw]*10+(a[i]-'0');
			sw++;
		}
	}
	sort(b,b+sw);
	for(int i=sw-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}
