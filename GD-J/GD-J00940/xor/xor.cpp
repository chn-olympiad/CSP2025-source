#include<bits/stdc++.h>
using namespace std;
int n,k,bj,lings,yis,ct;
int main(){
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int a[n+1]={0};
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]!=1)bj=1;
	}
	if(!bj)cout<<n/2;
	else{
		if(k==1){
			for(int i=1;i<=n;i++){
				if(lings==1&&yis==1){
					lings=0;
					yis=0;
					ct++;
				}
				if(a[i]==0)lings=1;
				else yis=1;
			}
		    cout<<ct;
		}
		else{
			for(int i=1;i<=n;i++){
			    if(a[i]==0)lings++;
			    if(a[i]==1) yis++;
				if(lings%2==0&&lings!=0){
				    lings=0;
				    ct++;
			    }
			    if(yis%2==0&&yis!=0){
			    	yis=0;
			    	ct++;
				}
		    }
		    cout<<ct;
		}
	}
	return 0;
}
