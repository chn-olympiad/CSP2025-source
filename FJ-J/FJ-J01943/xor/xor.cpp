#include<bits/stdc++.h>
using namespace std;
int n,m,i,a[500010];
bool A=true,B=true;
void X(){
	cout<<(n>>1);
	return;
}
void Y(){
	int p=0;
	if(m==1){
		for(i=1;i<=n;i++)
		if(a[i]==1)p++;
		cout<<p;
		return;
	}
	for(i=1;i<=n;i++){
		if(a[i]==0)p++;
		if(a[i]&&a[i+1])
		{p++;i++;}
	}
	cout<<p;
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	if(m!=0)A=false;
	if(m>1)B=false;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)A=false;
		if(a[i]>1)B=false;
	}
	if(A){X();return 0;}
	if(B){Y();return 0;}
	return 0;
}
