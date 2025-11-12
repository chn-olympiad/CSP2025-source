#include<bits/stdc++.h>
using namespace std;
int d[100];
int main(){
	freopen("seat.in","in",stdin);
	freopen("seat.out","out",stdout); 
	int a,s;
	cin>>a>>s;
	for(int i=0;i<a*s;i++){
		cin>>d[i];
	}
	int f=1,g=1;
	for(int i=1;i<a*s;i++){
		if(d[0]<d[i]&&f%2==1){
			g=g+1;
		}
		if(d[0]<d[i]&&f%2==0){
			g=g-1;
		}
		if(g>s&&f%2==1){
			g=s;
			f=f+1;
		}
		if(g==0&&f%2==0){
			g=1;
			f=f+1;
		}
	}
	cout<<f<<" "<<g;
	return 0;
}
