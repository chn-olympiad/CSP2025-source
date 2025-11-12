#include<bits/stdc++.h>
using namespace std;
bool cmp(int Ee,int Tt){
	return Ee>Tt;
}
int Rr,Nn,Mm,Qq=0,Kk=0,Ii=0;
int Aa[105]; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>Nn>>Mm;
	Qq=Nn*Mm;
	for(int i=0;i<Qq;i++){
		cin>>Aa[i];
		if(i==0){
			Rr=Aa[i];
		}
	}
	sort(Aa,Aa+Qq,cmp);
	for(int i=1;i<=Mm;i++){
		if(i%2==1){
			for(int j=1;j<=Nn;j++){
				if(Aa[Kk]==Rr){
					cout<<i<<" "<<j;
					return 0;
				}
				Kk++;
			}
		}
		else{
			for(int j=Nn;j>=1;j--){
				if(Aa[Kk]==Rr){
					cout<<i<<" "<<j;
					return 0;
				}
				Kk++;
			}
		}
	}
	return 0;
} 
