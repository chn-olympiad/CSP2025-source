#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r","std.in");
	freopen("polygon.out","w","std.out");
	int a,b;
	cin>>a;
	int c[a];
	for(int i=0;i<=a;i++){
	    cin>>c[i];
	    if(c[i]>c[i-1])
	    c[i]==c[i-1];  
	    else;
	    c[i-1]==c[i];
}
cout<<c[0];
return 0;
}
