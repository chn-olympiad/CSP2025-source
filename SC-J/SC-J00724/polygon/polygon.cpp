#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,a[5005],res,b[5005];
void p(int x,int y){
	int sum=0,maxn=0;
	for(int q=x;q<=y;q++){
		sum+=a[q];
		maxn=max(a[q],maxn);
	}
	if(sum>2*maxn){
		for(int w=x;w<=y;w++){
			if(b[a[w]]!=1){
				res+=b[a[w]]-1;
				b[a[w]]=1;
			}
		}
		cout<<endl;
		res++;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		int sum=0,maxn=0;
		for(int q=1;q<=n;q++){
		    sum+=a[q];
		    maxn=max(a[q],maxn);
	    }  
	    if(sum>2*maxn){
	    	cout<<1;
		}
		return 0;
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i;j<=n;j++){
			p(i,j);
		}
	}
	cout<<res%mod;
	return 0;
}