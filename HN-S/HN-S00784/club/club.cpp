#include<bits/stdc++.> 
using namespace std;
int main(){
	//freopen("club.in","r","stdin");
	//freopen("club.out","w","stdout");
	int n,ai1.ai2,ai3,m=0,c=0;
	cin>>n;
	for(int j=1;j<=n;j++){
			cin>>ai1>>ai2>>ai3; 
			if(ai1<ai2){
				m=ai2;
				if(m<ai3){
					m=ai3;
				}
			else{
				m=ai1;
			}
		c=c+m;
		}
	cout<<c;
	return 0;
}
