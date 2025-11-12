#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	int a;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n;
	cin>>m;
	cin>>a;
	for(int i=a;i<=100;i++){
		n=1||2||3||4||5;
		m=1||2||3||4;
		if(a){
			a=100||99||98||97;
			n=1;
			m=1||2||3||4;
			}
			if(a){
			a=96||95||94||93;
			n=2;
			}
			if(a){
			a=92||91||90||89;
			n=3;
			}
			if(a){
			a=88||87||86||85;
			n=4;
			}
			if(a){
			a=84||83||82||81;
			n=5;
			}
			m=1||2||3||4;
	}
		cout<<n<<m;
return 0;
}
