#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,c,d,s=0,n[10000],f[100]={0};
	cin>>a>>b;
	for(int i=1;i<=a*b;i++){
		cin>>n[i];
		f[n[i]]+=1;
	}
	for(int i=n[1];i<=100;i++){
		if(f[i]!=0){
			s+=1;
		}
	}
	if(a==1&&b==1){
		c=1;
	}else if(s%a==0){
		c=s/a;
	}else{
		c=s/a+1;
	}
	if(c%2!=0){
		d=s-a*(c-1);
	}else{
		d=a-s%(c-1);

	}
	cout<<c<<" "<<d;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}