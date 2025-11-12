#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int b[1000000];
int c[1000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	int k;
	cin>>n;
	cin>>k;
	//int answer;
	int cont=0;
	int cont2=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0)cont2+=1;
		if(a[i]==1)cont+=1;
			}
	int cont3=0;
	int cont4=0;
	for(int i=1;i<n;i++){
		if(a[i+1]==1 && a[i]==1)cont3+=1;
		if(a[i+1]==0){
			cont4+=(cont3+1)/2;
			cont3=0;}
}
	if(cont==n)cout<<n/2;
	else if(cont2+cont==n){
		if(k==1)cout<<cont;
		if(k==0)cout<<cont4+cont2;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
