#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

string a;
int b[N],n;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int s=a.size();
	for(int i=0;i<s;++i){
		if(a[i]>='0'&&a[i]<='9'){
			b[n++]=a[i]-'0';
		}
	}
	
	sort(b,b+n);
	for(int i=n-1;i>=0;--i){
		cout<<b[i];
	}
	return 0;
}