#include<bits/stdc++.h>
using namespace std;
int Nn,Mm,Aa[150],JIji;
bool pai(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>Nn>>Mm;
	for(int i=1;i<=Nn*Mm;i++){
		cin>>Aa[i];
	}
	JIji=Aa[1];
	sort(Aa+1,Aa+Nn*Mm+1,pai);
	for(int i=1;i<=Nn*Mm;i++){
		if(JIji==Aa[i]){
			cout<<((i-1)/Nn)+1<<" ";
			if((((i-1)/Nn))%2==0){
				if(i%Mm==0){
					cout<<Mm;
				}
				else{
					cout<<i%Mm;
				}
			}
			else{
				if(i%Mm==0){
					cout<<1;
				}
				else{
					cout<<Mm-(i%Mm)+1;
				}
				
			}
			return 0;
		}
	}
	return 0;
}