#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r".stdin);
	freopen("seat.out","w",stdout);
    int a,b;
    cin>>a>>b;
    int c[a*b];
    for(int i=0;i<a*b;i++){
		cin>>c[i];
	}
	int z=c[0];
	int l=a*b;
	sort(c,c+l);
	for(int i=0;i<a*b;i++){
		cout<<c[i]<<" ";
	}
	cout<<endl;
	int d=1,e=1;
	for(int i=l;i<0;i--){
		if(c[l]==z){
			cout<<"1 1"<<endl;
			return 0;
		}
		if(c[0]==z){
			cout<<"3 3"<<endl;
			return 0;
		}
		if(c[i]==z){
			cout<<i<<endl;
			if(i>b){
				e=i%a+a;
				d=i%a+2;
			}
			else{
				d=i;
			}
		}
	}
	cout<<d<<" "<<e<<endl;
    return 0;
}
