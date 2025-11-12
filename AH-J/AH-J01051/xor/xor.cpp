#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,cnt=0,z=0,y=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(z<=n&&y<=n){
		int shu;
		for(int i=z;i<=y;i++){
			if(i==z){
				shu=a[z];
			}else{
				shu=shu^a[i];
			}
		}
		if(shu==k){
			cnt++;
		}
		if(y!=n){
			y++;
		}else{
			z++;
		}
	}
	cout<<cnt;
	return 0;
}
