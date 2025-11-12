#include<bits/stdc++.h>
using namespace std;
string Ss;
int Nn,Aa[1000050],Bb;
bool pai(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>Ss;
	Nn=Ss.length();
	for(int i=0;i<Nn;i++){
		if(Ss[i]>='0'&&Ss[i]<='9'){
			Aa[Bb]=Ss[i]-48;
			Bb++;
		}
	}
	sort(Aa,Aa+Bb,pai);
	for(int i=0;i<Bb;i++){
		cout<<Aa[i];
	}
	return 0;
}