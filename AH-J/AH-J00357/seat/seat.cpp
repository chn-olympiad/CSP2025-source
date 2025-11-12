#include<bits/stdc++.h>
using namespace std;
int s[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,c;
	cin>>m>>n;
	int a=m*n;
	for(int i=0;i<a;i++){
		cin>>s[i];
	}
	int x=s[0],b=1;
	for(int i=1;i<a;i++){
		if(s[i]>x){
			b++;
		}
	}
	c=b/m;
	if(c%2==0){
		cout<<c<<' '<<b-c*m;
	}else{
		cout<<c<<' '<<m-(b-c*m);
	}
	return 0;
}
