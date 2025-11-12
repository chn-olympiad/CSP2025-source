#include<bits/stdc++.h>
using namespace std;
int a,b[1000],c[1000],d,e;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b[i];
	}
	sort(b,b+a);
	if(b[2]+b[1]>b[0]*2){
        cout<<1;
	}
	else{
        cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
