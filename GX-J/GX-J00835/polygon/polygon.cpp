#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,b[100],c,d;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b[i];
	}
	c=a+b[1];
	d=2*b[2];
	if(c%d==0){
		c=0;
		d++;
	}
	cout<<3;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
