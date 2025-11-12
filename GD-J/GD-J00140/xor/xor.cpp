#include<bits/stdc++.h>
using namespace std;
long long h[10005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,t=0;
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>t;
		h[i]=h[i-1]^t;
		//cout<<h[i]<<" ";
	}
	long long z=0;
	vector<int> x;
	vector<int> y;
	for(long long i=1,j=1,oi=1;oi<=n;i++,j++){
		if(i>n){
			i=1;
			j=oi+1;
			oi++;
		}
		//cout<<(h[j]^h[i-1])<<endl;
		if((h[j]^h[i-1])==k){
			bool f=0;
			for(int u=0;u<x.size();u++){
				//cout<<x[u]<<" "<<y[u]<<" "<<i<<" "<<j<<endl;
				if((x[u]>=i&&x[u]<=j)||(y[u]>=i&&y[u]<=j)){
					f=1;
					break;
				}
			}
			if(f==0){
				z++;
				x.push_back(i);
				y.push_back(j);
			}
		}
		
	}
	
	cout<<z;
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
//2 1 0 3
//2 3 3 3
//
