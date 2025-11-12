#include<bits/stdc++.h>//±©Á¦40·Ö 
using namespace std;
int a[500005];
int f[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			f[i]=1;
			cnt++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int flag=0,ans=a[i];
			for(int o=i+1;o<=j;o++){
				ans^=a[o];
				if(f[o]==1){
					flag=1;
					break;
				}
			}
			if(!flag && ans==k){
				//cout<<i<<" "<<j<<endl;
				for(int o=i;o<=j;o++){
					f[o]=1;
				}
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0; 
}
