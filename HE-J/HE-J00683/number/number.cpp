#include <bits/stdc++.h>
using namespace std;
string a;
const int c=1e6+5;
int b[c];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int j=0;
	for(int i=0;i<a.size();i++){
		if(a[i]-'0'<=9){
			j++;b[j]=a[i]-'0';
		}
	}
	sort(b+1,b+j+1,cmp);
	for(int i=1;i<=j;i++){
		cout<<b[i];
	}
	return 0;
}
