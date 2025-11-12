#include<iostream>;
#include<string>;
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long a[20][20],b,c,d,e=0,f,g;
	cin>>b>>c;
	for(int i=1;i<=b;i++){
		for(int j=1;j<=c;j++){
		if(i==1&&j==1){
			cin>>d;
		}
		else {
			cin>>a[i][j];
			if(a[i][j]>d){
				e++;
			}
		}
	}}
	e++;
	f=e/b+1;
	if(f%2==0){
		g=c-e%c+1;
	}
	else{
		g=e%c;
	}
	cout<<f<<" "<<g;
	return 0;
}
