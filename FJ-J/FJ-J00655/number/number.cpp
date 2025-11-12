#include<bits/stdc++.h>
using namespace std;
int b[100005],c=0;
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[++c]=int(a[i]-'0');
		}
	}sort(b+1,b+c+1);
	for(int i=c;i>=1;i--){
		cout<<b[i];
	}return 0;
} 
