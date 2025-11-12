#include <iostream>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdin);
	int a,a1=0,a2=0,a3=0;
	cin>>a;
	int b[a];
	for(int c=0;c<a;c++){
		int e=0,f;
		cin>>f;
		int d[f];
	for(int c=0;c<f;c++){
		for(int c=0;c<3;c++){
			cin>>d[c];
		}
		if(d[0]>d[2] && d[0]>d[1]){
				a1++;
				if(f/2>a1||f/2==a1){
						e=e+d[0];
				}else{
					e=e+d[2];
				}
			}
		else if(d[1]>d[0] && d[1]>d[2]){
				a2++;
				if(f/2>a2||f/2==a2){
					e=e+d[1];
				}else{
					e=e+d[2];
				}
			}
		else if(d[2]>d[1] && d[2]>d[0]){
				a3++;
				if(f/2>a3||f/2==a3){
				e=e+d[2];
			}else{
					e=e+d[2];
			}
			}
		}
		cout<<e;
	}
	return 0;
}
