#include <bits/stdc++.h>
using namespace std;

int t ,n,a1 ,a2, a3,c,d,e[10005],f,g;
int main(){
	//freonpen("club.in","r",stdin );
	//freonpen("club.out","w",stdouy );
	cin>>t;
	f=0;
	g=0;
	for (int i=0;i<=t ;i++) {
		cin>>n;
		if(n%2==1){
			n=n-1;}
		for  (int i=0;i<=n;i++){
			cin>>a1>>a2>>a3;
			if(a1>a2){
				c=a1;
			}
			if(a2>=a1){
				c=a2;
			}
			if(a3>c){
				c=a3;
			}
		d=c+d;
		}
		e[f]=d;
		f++;
	
	}
	for(int i=0;i<=n+1;i++){
		g=g+e[i];
	}
	cout<<'g';
	return 0;
}
