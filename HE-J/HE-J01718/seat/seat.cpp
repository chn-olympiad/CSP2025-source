#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1,mc=0;
	cin>>n>>m;
	int s[1000];
	int s2[105]={0};
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
		a1=s[1];
		s2[s[i]]=1;
	}
	for(int i=1;i<=101;i++){
		if(i==a1){
			break;
		}
		if(s2[i]==1){
			mc++;
		}
	}
	mc=n*m-mc;
	if(mc/m==1 && mc%m==0){
		cout<<1<<" ";
	}else{
		cout<<mc/m+1<<" ";
	}
	
	if(mc%m>0 && ((mc/m)%2)==1){
		cout<<m-(mc%m-1);
	}else{
		cout<<mc%m;
	}
}
