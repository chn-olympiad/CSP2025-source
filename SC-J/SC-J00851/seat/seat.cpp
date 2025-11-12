#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in ","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,ming,s=0,d=0,e;
	cin>>a>>b;
	int num=a*b;
	int n[num],p[num];
	for(int i=0; i<num; i++) {
		cin>>n[i];
	}
	ming=n[0];
	for(int j=0; j<num; j++) {
		for(int i=0; i<num; i++) {
			if(n[i+1]>n[i]&& i+1<num) {
				s=n[i];
				n[i]=n[i+1];
				n[i+1]=s;	
			}
		}
	}
	for(int i=0; i<num; i++) {
		if (n[i]==ming) d=i+1;
		
	}
	
	double c=d*1.0/b;
	if (int(c)<c && int(c)+1>c){
		e=int(c)+1;
	}else{
		e=int(c);
	}
	int ji=d-((e-1)*a);
	if (e==1) cout<<1<<" "<<d;
	else{
		if(e%2==1){
			cout<<e<<" "<<ji;
		}else{
			cout<<e<<" "<<a-ji+1;
		}
	}
}