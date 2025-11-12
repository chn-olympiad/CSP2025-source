#include<iostream>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,b,c,max = 0;
	cin >> a >> b >> c;
	if(a > max) max = a;
	if(b > max) max = b;
	if(c > max) max = c;
	if(a + b + c > max * 2){
		cout << 1;
	}else cout << 0;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

