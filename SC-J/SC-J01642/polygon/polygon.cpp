#include<iostream> 
#include<algorithm>
using namespace std; 
int a,b,c;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n:
	cin>>a>>b>>c;
	int k=max(a,b);
	if(k>=c){
		if(2*k<(a+b+c))cout<<1;
		else cout<<0;
	}
	else{
		if(c*2<(a+b+c))cout<<1;
		else cout<<0;
	}
	return 0;
}