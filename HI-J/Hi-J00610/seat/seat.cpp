#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
    int b,c,d=0,e=0,f=0,g=0;
    cin>>b>>c;
    for(int i=0;i<b*c;i++){
    	cin>>a[i];
	}
	for(int i=0;i<b*c;i++){
		d=a[i];
		break;
	}
	e=100;
	f=0;
	for(int i=0;i<b;i++){
		f++;
		for(int j=0;j<c;j++){
			if(f%2==0) g--;
			else g++;
			if(e==d){
				if(f%2==0){
					cout<<f<<" "<<g+1;
					return 0;
				}
				else{
					cout<<f<<" "<<g;
					return 0;
				}
			}else e--;
		}
	}
	return 0;
}
