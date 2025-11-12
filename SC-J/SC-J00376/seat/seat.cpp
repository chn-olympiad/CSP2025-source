#include<bits/stdc++.h>
using namespace std;
const int N=100;
int c[N];
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out ","w",stdout);
	int a=0,b=0;
	cin>>a>>b;
	for(int i=0;i<a*b;i++){
			cin>>c[i];
	}
	int g=c[0];
	sort(c,c+a*b);
	for(int i=0;i<=a*b;i++){
		if(c[i]==g){
			g=i;
			break;
		}
	}
	g=a*b-g-1;
	if((g/a+1)%2==1){
		cout<<g/a+1<<" "<<g%a+1;
	}
	else {
		cout<<g/a+1<<" "<<a-(g%a);
	}
	return 0;
}