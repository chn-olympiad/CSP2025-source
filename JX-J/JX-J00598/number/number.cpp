#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000001],c,o;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int c=a.size();
	for(int i=0;i<c;i++){
		if(a[i]<='9'&&a[i]>='0'){
			b[++o]=a[i]-'0';
		}
	}
	sort(b+1,b+o+1);
	for(int i=o;i>=1;i--){
		cout<<b[i];
	}
}
