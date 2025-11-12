#include <bits\stdc++.h>
using namespace std;
int main(){
	freopen('number.in','r',stdin);
	freopen('number.out','w',stdout);
	string a;
	int b,c[1001],d = 0;
	cin>>a;
	b = a.length();
	for(int i=0;i<b;i++){
		if (a[i]>='0' && a[i]<='9'){
			c[d] = (int)a[i]-(int)'0';
			d++;
		}
	}
	sort(c,c+d);
	for(int i=d-1;i>=0;i--){
		cout<<c[i];
	}
	fcloce(stdin);
	fclose(stdout);
	return 0;
}
