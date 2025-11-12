#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000010],c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int h=a.size();
	for(int i=0;i<h;i++){
		if(a[i]<='9'&&a[i]>='0'){
			b[++c]=a[i]-'0';
		}
	}
	sort(b+1,b+1+c);
	for(int i=c;i>=1;i--){
		cout<<b[i];
	}
	return 0;
}
