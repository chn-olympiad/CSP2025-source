#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int c=0,b[1145141];
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[c]=(a[i]-'0');
			c++;
		}
	}
	sort(b,b+c);
	for(int i=c-1;i>=0;i--) cout<<b[i];
	cout<<endl;
	return 0;
}
