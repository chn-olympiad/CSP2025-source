#include <bits/stdc++.h>
using namespace std;
string a;
short b[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>a;
	int j=0;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9') {
			b[j]=a[i]-'0';
			j++;
		}
	}
	sort(b,b+j,cmp); 
	for(int i=0;i<j;i++) cout <<b[i];
	return 0;
}
