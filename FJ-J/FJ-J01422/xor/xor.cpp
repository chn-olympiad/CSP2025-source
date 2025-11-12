#include <bits/stdc++.h>
using namespace std;
int main () {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a=0,b[1001],c,s=0;
	cin>>a>>c;
	for(int i=1;i<=a;i++){
		cin>>b[i];
		s++;
		
	}
	if(s%2!=0)
	cout<<"2";
	scanf("%d",&a);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
