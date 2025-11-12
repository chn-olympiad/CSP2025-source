#include <bits/stdc++.h>
using namespace std;
int a,b[100],yg=0,o=0;
int nb(int h,int s,int w){
	w+=1;
	if(w>=3){
		yg+=1;
		}
	for(int i=s;i<a;i++){
		if(h>b[i]){
			nb(h+b[i],i,w);
		}
	}
	return 0;
}
int main(){
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    cin>>a;
    for(int i=0;i<a;i++){
		cin>>b[i];
	}
	for(int i=0;i<a-2;i++){
		for(int j=i;j<a-1;j++){
			 nb(b[i]+b[j],j,1);
			}
	}
    return 0;
    }
