#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000000],sum=0; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) sum++;
	}
	if(k==0) cout<<sum;	
	else if(k==1||k==3){
		for(int i=1;i<=n;i++){
			if(a[i]!=k&&a[i+1]!=k&&((a[i+1]==a[i]+1)||(a[i+1]==a[i]-1))){
				int x=min(a[i],a[i+1]);
				if(k==1&&x%2==0) sum++;
				else if(k==3&&x%2!=0) sum++; 
			}
		}
		cout<<sum;
	}
	return 0;
}
