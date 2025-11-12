#include<bits/stdc++.h>
using namespace std;
int b[1000005],z=1;
bool ab(int x,int y){
	return x>y; 
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int c=0;c<a.size();c++){
		if(a[c]>='0'&&a[c]<='9'){
			b[z]=a[c]-'0';
			z++;
		}
	} 
	sort(b+1,b+1+z,ab);
	for(int c=1;c<z;c++) cout<<b[c];
	return 0;
} 
