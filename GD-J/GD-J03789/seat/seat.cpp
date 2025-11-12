#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("seat.in","r".,stdin);
	//freopen("seat.out","w",stdont);
	int n,m,c,d,f,e=1;
	cin>>n>>m;
	int a=n*m;
	cin>>c;
	for(int i=1;i<a;i++){
		cin>>d;
		if(d>c){
			e++;
		}
	}
	int s=e/m+1;
	if(s%2){
		f=e%m;
	}
	if(s%2==0){
		f=n-(e%m);
	}
	cout<<s<<" "<<f;
	return 0;
} 
