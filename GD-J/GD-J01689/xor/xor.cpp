#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn=5e5+2;


struct nood{
	
	int l,r;
	
}b[maxn];

ll pre_a[maxn],a[maxn];


int main(){
	
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr); 
	
	ll n,k;
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		
		cin>>a[i]; 
		
	}	
	
	pre_a[1]=a[1];

	for(ll i=2;i<=n;i++){
		
		pre_a[i]=(pre_a[i-1] xor a[i]);
		
	}
	
	ll sum=0;
	
	
	for(int l=1;l<=n;l++){
		
		for(int r=l;r<=n;r++){
			
			if(abs(pre_a[r]-pre_a[l-1])==k) {
				
				sum++;
				b[sum].l=l,b[sum].r=r;
				
			}
			
		}
		
	}	

	for(int i=1;i<=sum;i++){
		
		for(int j=1;j<=sum;j++){
			
			if(i!=j and i<j){
				
				
				if((b[i].l<b[j].l and b[i].l<b[j].r and b[i].r<b[j].r and b[i].r<b[j].l) or (b[i].l>b[j].l and b[i].l>b[j].r and b[i].r>b[j].r and b[i].r>b[j].l)) {
					
					continue;
					
				}
				else sum--; 
				
			}
			
		}
		
	}
	
	cout<<sum<<endl;
	
	return 0; 
	
}
