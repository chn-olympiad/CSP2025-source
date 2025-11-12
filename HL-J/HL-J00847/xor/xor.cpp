#include <bits/stdc++.h>
using namespace std;
int a[100005];
int n,k;
int coun=0;
int cort=0;
int b[100005];
int ggt(int x,int y){
	int ty=1;
	int opp=1;
	while(opp){
		b[ty]=(x%2)^(y%2);
		x/=2;
		y/=2;
		ty+=1;
		if(x==0&&y==0){
			opp=0;
		}
	}
	opp=1;
	int io=0;
	int tu=0;
	int tu2=1;
	while(opp){
		io+=pow(2,tu)*b[tu2];
		tu+=1;
		tu2+=1;
		if(tu2>ty){
		  opp=0;
		}
		
	}
	return io;
}
bool kww(int x,int y,int s){
	if(ggt(x,y)==s){
		return 1;
	}
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=1&&a[i]>=0){
			coun+=1;
		}
	}
	if(coun==n){
		cout<<0;
		return 0;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				cort+=1;
			}
		}
		cout<<cort;
		return 0;
	}
	int ty=0;
	for(int i=1;i<n;i++){
		 ty=a[i];
		if(kww(ty,ty,k)){
			cort+=1;
			
		}
		else{
			for(int j=i;j<n-1;j++){
		       if(kww(ty,a[j+1],k)){
			     cort+=1;
			     
			     break;
		       }
		       ty=ggt(ty,a[j+1]);	
		    }
		}	
	}
	cout<<cort;
	return 0;
}                                                                           
