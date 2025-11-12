#include <iostream>
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int main (){
	freopen("seap.in","r",stdin);
	freopen("seap.out","w",stdout);
	int x,y,l,me,ned,a=0,b=0,s,h=0;
	cin>>x>>y;
	l=x*y;
	int aq[l];
	aq[0]=0;
	for(int i=0;i<l;i++){
		cin>>aq[i];
	} 
	me=aq[0];
	for(int i=0;i<l;i++){
		for(int j=0;j<l;j++){
			if(aq[j]<aq[j+1]){
				s=aq[j];
				aq[j]=aq[j+1];
				aq[j+1]=s;
			}
		}
	}
	for(int i=0;i<l;i++){
		if(aq[i]==me){
			ned=i+1;
		}
	}
	if(ned%2==0){
		h=ned/x;
		b=ned%x+2;
	}else{
		h=ned/x;
		b=ned%x+1;
	}
	
		cout<<h<<" "<<b; 
	
}
