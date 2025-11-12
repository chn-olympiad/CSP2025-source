#include <bits/stdc++.h>
using namespace std;
int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a=0,b[1001],s=0,c=0;
	cin>>a>>c;
	for(int i=1;i<=a;i++){
		cin>>b[i];
		s++;
		
	}
	if(s%2!=0)
	cout<<"1"<<"2";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
