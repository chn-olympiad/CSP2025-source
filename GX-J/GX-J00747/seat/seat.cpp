#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	int a,b,c,d=1,h=0,l=0;
	
	cin>>a>>b;
    c=a*b;
    int e[c];
    cin>>e[0];
    for(int i=1;i<c;i++){
		cin>>e[i];
		
		
		}
	for (int j=1;j<c;j++){
		if (e[0]<e[j]){
			d+=1;
			}
	}
	if((d/b)%2==0){
		l=d/a;
		if(d%a!=0){
			l=d/a+1;}
		h=l-d/b;
		
		if(d%b==0){
			h=l-(d/b+1);
			}
		
		
		}
	if((d/b)%2!=0){
		l=d/a;
		if(d%a!=0){
			l=d/a+1;}
		h=d/b;
		if(d%b==0){
			h=d/b+1;
			}
		
		
		}
		
	
	cout<<l<<" "<<h;
	return 0;
	}
