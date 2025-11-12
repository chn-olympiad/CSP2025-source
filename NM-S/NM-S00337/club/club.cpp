#include <iostream>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int m = 0;
	int d,e,f= 0;
	for(int i = 1;i <= t;i++){
		int n;
		cin >> n;
		for(int j =1;j <= n;j++){
			int a,b,c;
			cin>>a>>b>>c;
			if(a>b&&a>c){
				m = m+a;
			}else if(b>a&&b>c){
				m = m+b;
			}else{
				m = m+c;
			}
			
		}if(i == 1){
		d = m;
		m = 0;
	}if(i == 2){
		e = m;
		m = 0;
	}if(i == 3){
		f = m;
		m = 0;
	}
}cout<<d<<endl<<e<<endl<<f;
return 0;
}
