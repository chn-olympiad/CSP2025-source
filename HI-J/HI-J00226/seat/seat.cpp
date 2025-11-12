#include<bits/stdc++.h>
using namespace std;
bool t(int l,int r){
	return l>r;
}
int y[13][13];
int p[109];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int z=0,h=0,m=0;
	cin>>z>>h;
	for(int i=1;i<=z*h;i++){
		cin>>p[i];
		if(i==1){
			m=p[i];
		}
	}
	int f=1;
	sort(p+1,p+z*h+1,t);
	for(int i=1;i<=z*h;i++){
		if(p[i]==m){
			m=i-1;
			break;
		}
	}
	bool g=1;
	int m1n=1,m2n=1;
	while(m){
		if(g){
			if(m1n!=z){
				m1n++;
			}else{
				g=0;
				m2n++;
			}
			m--;
			
		}else{
			if(m1n!=1){
				m1n--;
			}else{
				g=1;
				m2n++;
			}
			m--;
		}
	}
	cout<<m2n<<" "<<m1n;
	return 0;
}
