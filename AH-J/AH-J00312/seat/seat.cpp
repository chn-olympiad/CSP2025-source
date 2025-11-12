#include<bits/stdc++.h>
using namespace std;
int n,m,Yss_a;
int Yss_p[1939],Yss_ans=1,Yss_l,Yss_h;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>Yss_a;
	for(int i=1;i<n*m;i++){
		int Yss_temp;
		cin>>Yss_temp;
		Yss_p[Yss_temp]++;
	}
	for(int i=100;i>=1;i--)
	{
		if(i==Yss_a)break;
		Yss_ans+=Yss_p[i];
	}
	Yss_l=Yss_ans/n;
	if(Yss_l*n==Yss_ans){
		if(Yss_l%2==1)Yss_h=n;
		else Yss_h=1;
	}
	else{
		Yss_h=Yss_ans-Yss_l*n;
		Yss_l++;
		if(Yss_l%2==0)Yss_h=n-Yss_h+1;
	}
	cout<<Yss_l<<' '<<Yss_h;
	return 0;
}
