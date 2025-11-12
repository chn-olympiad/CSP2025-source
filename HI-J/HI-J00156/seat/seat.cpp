#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,m;
	cin>>a>>m;
	int a1[a*m],max;
	for(int i=0;i<a*m;i++){
		cin>>a1[i];
	}
	int ri,r=a1[0];
	sort(a1,a1+(a*m));
	for(int i=0;i<a*m;i++){
		if(a1[i]==r){
			ri=a*m-i;
			break;
		}
	}
	int q=0;
	if(ri%a>0){
		cout<<ri/a+1;
		
	}
	else{
		cout<<ri/a;
	}
	cout<<" ";
	if(ri<=m){
		cout<<ri;
	}
	else if(a==1&&m==1){
		cout<<1;
	}
	else{
		if(ri%a!=0){
			cout<<ri%a+1 ;
		}
		else{
			cout<<m-ri%a+1;
		}
	}
	return 0;
}
