#include<bits/stdc++.h>
using namespace std;
vector<int> Sum(int al,int bl,vector<int> A,vector<int> B){
	vector<int> C;
	for(int i=0;i<max(al,bl);i++){
		if(i<abs(al-bl)||al!=bl){
			if(al>bl){
				if(A[al-1-i]==0) C.push_back(0);
				else C.push_back(1);
			}else {
				if(B[bl-1-i]==0) C.push_back(0);
				else C.push_back(1);
			}
		}else{
			if(B[bl-1-i]==A[bl-1-i]) C.push_back(0);
			else C.push_back(1);
		}
	}
	return C;
}
int Xor(vector<int> a,int l,int r){
	int q=r-l;
	if(q==0) return a[0];
	vector<vector<int> > A(q);
	int x[q];
	for(int j=l;j<r;j++){
		x[j]=a[j];
	}
	for(int i=0;i<q;i++){
		while(x[i]>0){
		A[i].push_back(x[i]%2);
		x[i]=(x[i]-x[i]%2)/2;
	    }
	}
	int al[q];
	for(int i=0;i<q;i++){
		al[i]=A[i].size();
	}
	vector<int> C=Sum(al[1],al[0],A[1],A[0]);
	if(q>2){
		for(int i=2;i<q;i++){
		C=Sum(al[i],C.size(),A[i],C);
	}
	}
	int sum=0;
	for(int j=0;j<C.size();j++){
		sum=sum*2+C[C.size()-j-1];
	}
	return sum;
}
int xorMax(vector<int> a,int k){
	int r1=0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int> a(n);         
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	return 0;
} 
