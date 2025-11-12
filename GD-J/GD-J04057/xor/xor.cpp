#include <bits/stdc++.h>
using namespace std;
int nnm[500001];
int n,k;
int nt(int g){
	int y=2;
	if(g==0){
		return 1;
	}
	for(int i=1;i<g;i++){
		y=y*2;
	}
	return y;
}
string npt(int k){
	string kkl="",uul="";
	while(k!=0){
		if(k%2==1){
			kkl=kkl+"1";
		}
		else{
			kkl=kkl+"0";
		}
		k=k/2;
	}
//	int t=kkl.size();
//	for(int i=0;i<kkl.size();i++){
//		t--;
//		uul=uul+kkl[t];
//	}
	return kkl;
}
string orx(string b,string a){
	int k;
	string opo="";
	string ak=a,bk=b;
	if(ak.size()<bk.size()){
		for(int i=0;i<bk.size()-ak.size();i++){
			opo=opo+"0";
		}
		ak=ak+opo;
	}
	else if(ak.size()>bk.size()){
		for(int i=0;i<ak.size()-bk.size();i++){
			opo=opo+"0";
		}
		bk=bk+opo;
	}
	string ppk="";
	for(int i=0;i<bk.size();i++){
		if(ak[i]!=bk[i]){
			ppk=ppk+"1";
		}
		else{
			ppk=ppk+"0";
		}
	}
	return ppk;
}
int npy(string k){
	int mmu=0;
	for(int i=1;i<=k.size();i++){
		if(k[i-1]=='1'){
			mmu=mmu+nt(i-1);
		}
	}
	return mmu;
}
int miil(int s){
	int mix=0;
	for(int l=s;l<n;l++){
		for(int r=l;r<n;r++){
			int op;
			op=npy(orx(npt(nnm[l]),npt(nnm[r])));
			for(int i=1;i<r-l;i++){
				op=npy(orx(npt(op),npt(nnm[r])));
			}
			if(op==k){
				mix=max(mix,miil(l));
			}
		}
	}
	cout<<mix+1;
	return mix+1;
} 
int miii(int s){
	int mix=0;
	for(int l=s;l<n;l++){
		for(int r=l;r<n;r++){
			int op;
			op=npy(orx(npt(nnm[l]),npt(nnm[r])));
			for(int i=1;i<r-l;i++){
				op=npy(orx(npt(op),npt(nnm[r])));
			}
			if(op==k){
				mix=max(mix,miil(l));
			}
		}
	}
	
	return mix;
} 
int main(){
	freopen("orx.in","r",stdin);
	freopen("orx.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>nnm[i];
	}
	cout<<miii(0);
	return 0;
}
//4 0 2 2 1 0 3























/*
        /  	   /    /"""""""    /          /          /""""""/
       /	  /    /           /          /          /      /
      /------/    /-------    /          /          /      /
     /      /    /           /          /          /      /
    /      /    /_______	/_______   /_______   /______/
 
    [                /
    ]      /]      / 
    [    /  [    /    
    ]  /    ]  /      
    [/      [/
*/
