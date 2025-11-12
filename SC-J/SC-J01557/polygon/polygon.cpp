#include<bits/stdc++.h>
using namespace std;
int l[5000],m,n;
int bn[5000];
int a(int b){
	if(b==3){
		if(bn[0]+bn[1]+bn[2]>2*max(max(bn[0],bn[1]),bn[2]))return 0;
		return 1;
	}
	int sum=0,maxl=0;
	for(int i=b;b>3;b--){
		sum+=l[i];
		if(l[i]>2*maxl)maxl=l[i];
	}
	int s=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j>=i)bn[i]=bn[i-1];
			else bn[i]=bn[i];
		}
		s=a(b-1);
	}
	if(sum>2*maxl)return (1+s)%998225353;
	else return s%998225353;
}
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	int n;cin>>n;
	for(int i=0;i<n;i++){
		cin>>l[i];
		bn[i]=l[i];
	}
	cout<<a(n)+1;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}