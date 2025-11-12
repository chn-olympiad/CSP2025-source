#include <bits/stdc++.h>
using namespace std;
string a;
int b[1000010],len=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[++len]=a[i]-'0';
		}
	}
	sort(b+1,b+len+1);
	for(int i=len;i>=1;i--){
		printf("%d",b[i]);
	}
	return 0;
} 
