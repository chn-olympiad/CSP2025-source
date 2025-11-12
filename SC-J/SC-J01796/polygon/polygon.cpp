#include<bits/stdc++.h>
using namespace std;
int size[100000]={0};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>size[i];
	}
	for(int i=1;i<=n;i++){
		int max_size=0;
		int sizee=0;
		for(int j=i;j<=n;j++){
			if(j<3)continue;
			else{
				for(int k=1;k<=j;k++){
					max_size=max(size[k],max_size);
					sizee+=size[k];
				}
				if(sizee>2*max_size){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}