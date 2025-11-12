#include<bits/stdc++.h>
using namespace std;
long long m[1000001],n[1000001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long j,k,sum=0,op=0;
	cin>>j>>k;
	for(int i=1;i<=j;i++){
		cin>>m[i];
		if(m[i]==k) m[i]=-1,sum++;
	}
	for(int i=1;i<=j;i++){
		op=0;
		for(int p=2;p<=j;p++){
			for(int y=i;y<=i+p;y++){
				op^=m[y];
				if(op==k){
					sum++;
					i=y;
					break;
				}
			}	
		}
		
	}	
	cout<<sum;
	return 0;
} 
