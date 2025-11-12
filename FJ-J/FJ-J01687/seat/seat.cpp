#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a=n*m;
	char b[a];
	int c=0;
	int d=0;
	for(int i=0;i<a;i++){
		cin>>b[a];
		if(n<=1&&m<=1){
			cout<<n<<" "<<m;
			break;
		}
		if(n<=1&&m>=0&&m<=10){
			if(b[i]>b[i+1]){
				c++;
			}
			cout<<n<<" "<<c;
			break;
		}
		if(n<=10&&m<=10){
			if(b[i]>b[i+1]){
				c++;
				d++;
				d%=10;
				
			}
			cout<<d<<" "<<c;
			break;
		}
	}
	return 0;
}
