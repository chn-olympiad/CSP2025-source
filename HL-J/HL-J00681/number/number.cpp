#include<bits/stdc++.h>
using namespace std;
string a,c;
char b[1000010],d[1010];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	c=a;
	for(int i=0;i<a.size();i++){
		if((int(a[i]))>=48&&(int(a[i]))<=57){
			d[i]=a[i];
		}
	}
	sort(d,d+a.size(),cmp);
	for(int i=0;i<a.size();i++){
		cout<<d[i];
	}
	return 0;
}
