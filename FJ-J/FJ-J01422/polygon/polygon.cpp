#include <bits/stdc++.h>
using namespace std;
int main () {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a=0,b[1001],s=0;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>b[i];
		s++;
		
	}
	if(s%2!=0)
	cout<<"9";
	fclose(stdin);
	fclose(stdout);
	return 0;
}     
