#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,c[105],d=0,m=0;
	cin>>a>>b;
	d=0;
	for(int i=0;i<a*b;i++){
		cin>>c[i];
	}
	m=c[0];
	sort(c+0,c+b*a,cmp);
	for(int i=1;i<=b;i++){
		if(i%2!=0){
			for(int j=1;j<=a;j++){
				if(c[d]==m)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				d++;
			}	
		}
		else{
			for(int j=a;j>0;j--){
				if(c[d]==m){
					cout<<i<<" "<<j;
					return 0;
				}
				d++;
			}
		}
		
	}
	return 0;
}
