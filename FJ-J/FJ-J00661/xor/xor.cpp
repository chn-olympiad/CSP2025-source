#include<bits/stdc++.h>
using namespace std;
int a[50005],h[50005],n,k,ans,sum,hea;
bool f[50005];
bool chek(bool s[],int l,int r){
	for(int i=l;i<=r;i++){
		if(s[i])return 0;
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	//cout<<(0^1)<<endl;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			f[i]=1;
			h[++hea]=i;
		}
	}
	h[hea+1]=n+1;
	//int i;
	/*for(int i=1;i<=n;i++){
		cout<<f[i]<<" ";
	}
	cout<<endl;
	cout<<h[1]<<endl;*/
	for(int i=0;i<=hea;i++){
		
		int l=1;
		while(l<h[i+1]-h[i]-1){
			l++;
			sum=a[h[i]+1];
			for(int j=h[i]+1;j<h[i+1];j++){
				//cout<<"a"<<endl;
				if(chek(f,j,j+l-1)){
					sum=a[h[i]+1];
					for(int z=j;z<j+l-1;z++){
						sum^=a[z+1];
						//cout<<sum<<endl;
					}
					if(sum==k){
						ans++;
						//cout<<"a"<<endl;
						for(int z=j;z<=j+l;z++)f[z]=1;
					}
				}
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		cout<<f[i]<<" ";
	}
	cout<<endl;*/
	cout<<ans;
	return 0;
}
