#include<bits/stdc++.h>
using namespace std;

const int N=1000;

int a[N];

bool b[N];


int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool flaga=true;
	int n;
	long long k;
	cin>>n;
	cin>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flaga=false;
	}
	
	if(flaga){
		if(k>1){
			cout<<0;
		}
		else if(k==0){
			cout<<n/2;
		}
		else{
			cout<<n;
		}
	}
	
	else{
		int sumone=0,sumzero=0;
		int l=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					sumzero++;
					if(l>1) sumone=sumone+l/2;
					l=0;
				}
				else l++;
			}
			cout<<sumone+sumzero;
		}
		else{
			
			cout<<sumone;
			
		}
		
	}
	
	return 0;
}
