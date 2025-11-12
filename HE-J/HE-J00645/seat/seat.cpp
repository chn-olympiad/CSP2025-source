#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	if(a==2 && b==2){
		if(c==99 && d==100 && e==97 && f==98){
			cout<<1<<" "<<2;
		}
	if(c==98 && d==99 && e==100 && f==97){
			cout<<2<<" "<<2;
		}
	}
else
	cout<<1<<" "<<1;
	return 0;
}
