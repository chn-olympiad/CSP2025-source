#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[1000005],w=0,q=0;
	cin>>s;
	while(s[q]){
		if(s[q]>='0'&&s[q]<='9'){
			a[w]=(int)s[q]-48;
			w++;
		}
		q++;
	}
	sort(a,a+w);
	for(int i=w-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
