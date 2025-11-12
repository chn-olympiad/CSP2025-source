#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],k=0;
string c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,c);
	int len=c.size();
	for(int i=0;i<len;i++){
		if(c[i]>='0'&&c[i]<='9'){
			a[k]=int(c[i]-'0');
			k++;
		}
	}
	sort(a,a+k);
	for(int i=k-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 