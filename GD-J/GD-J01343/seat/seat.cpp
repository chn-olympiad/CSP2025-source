#include<bits/stdc++.h>
using namespace std ;

int main(){
	int n,m;
	cin>>n>>m;
	int x[n*m+5],y[n*m+5];
	cin>>x[0];
	int z = x[0];
	for(int i=1;i<n*m;i++){
		cin>>x[i];
	}
	sort(x,x+n*m);
	int c=0;
	for(int i=n*m;i>0;i--){
		y[c] = x[i];
		c++;
	}
	int num;
	for(int i=0;i<n*m;i++){
		if (y[i]== z) {
			num = i;
		}
	}
	int a=0,b=0;
	while(num>0){
		if (num>=m) {
		    num-=m;
		    a++;
		}
		else {
			if (a % 2 == 1){
				a++;
				b = m-num%m;
				break ;
			}
			else{
				a++;
				b = num%m;
				break;
			}
		}
	}
	if(a == 0) a = 1;
	if(b == 0 && a % 2 == 0) b = 1;
	if(b == 1 && a % 2 == 0) b =m;
	if(b == 0 && a % 2 == 1) b =m;
	cout<<a<<" "<<b;
	return 0;
}
