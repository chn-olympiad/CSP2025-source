#include<bits/stdc++.h>
using namespace std;
int a[500025];
int n,k,maxf[500025],maxmaxf;
int chai(int aa,int bb){
	int i=1,achai[25]={0},bchai[25]={0},ch;
	while(aa!=0){
		achai[i]=aa%2;
		aa/=2;
	}
	while(bb!=0){
		bchai[i]=bb%2;
		bb/=2;
	}
	for(int i=1;i<=22;i++){
		if(achai[i]==1&&bchai[i]==1)achai[i]=0;
		else achai[i]=1;
		for(int j=1;j<=i;j++) achai[i]*=2;
		ch+=achai[i];
	}
	return ch;
}
void fxor(int x,int s){
	if(chai(s,a[x])==k){maxf[y]+=1;fxor(x+1,0);}
	else fxor(x+1,chai(s,a[x]));
}
int main(){
	freopen("xor.out","w",stdout);
	freopen("xor.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int y=1;y<=n;y++){
		fxor(y,0);
		maxmaxf=max(maxmaxf,maxf[y]);
	}
	cout<<maxmaxf;
	return 0;
}
