#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,k,sum;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];		
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0)sum++;		
			else if(a[i]==a[i+1]){
				sum++;
				i++;
			}
		}
	}
	else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1)sum++;		
		}
	}
	else{
		int l=1,r=1,f=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				sum++;
				l=i+1;
				r=l;
			}
			int cnt=a[l];
			for(int j=l+1;j<=r;j++){
				f=0;
				cnt=cnt^a[j]; 
				if(cnt==k){
					sum++;
					l=j+1;
					r=l;
					f=1;
					break;
				}
			}
			if(a[i]!=k&&f==0)r++;		
		}
	}
	cout<<sum;
}  