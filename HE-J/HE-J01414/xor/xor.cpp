#include <bits/stdc++.h>
using namespace std;
int n,k,op=0;
int a[1001000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int l=0,r;
	if(k==0){
		while(r<n){
		int ent;
		for(r=l;r<n;r++){
			if(r==l){
				ent=a[r];
			}else{
			
				ent=ent^a[r];
			
				
			}
			
			if(ent==k){
				l=r+1;
				op++;
				break;
			}
		}l++;
		r=l;
	}cout<<op;
	return 0;
	}
	while(r<n){
		int ent;
		for(r=l;r<n;r++){
			if(r==l){
				ent=a[r];
			}else{
			
				ent=ent^a[r];
			
				
			}
			
			if(ent==k){
				l=r+1;
				op++;
				break;
			}if(ent>k){
				l++;
				break;
			}
		}
	}
	cout<<op;
	
	return 0;
	
}
