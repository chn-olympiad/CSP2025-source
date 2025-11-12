#include<bits/stdc++.h>
using namespace std;
long long n,k,a[15005],b[15005][15005]={0},l,r,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	    cin>>a[i];
	for(int i=0;i<n;i++){
		b[i][i]=a[i];
		//cout<<b[i][i]<<" ";
		for(int j=1;j+i<n;j++){
			b[i][i+j]=(b[i][i+j-1]^a[i+j]);
			//cout<<b[i][i+j]<<" ";
		}
		//cout<<endl;
	}//生成异或数组 
	while(l<n){
		if(b[l][r]==k){
			//cout<<b[l][r]<<" "<<l<<" "<<r<<endl;
			ans++;
			l=r+1;
			r=l;
		}
		else if(r>n){
			l++;
			r=l;
		}
		else{
			r++;
		}
	}
	cout<<ans;
	return 0;
} 
