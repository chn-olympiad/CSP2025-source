#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000010],ans,b[1000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			b[i]=1;
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		int num=a[i];
		if(b[i]!=1){
			int p=0,pp=0;
			for(int j=i+1;j<=n;j++){
				num=num xor a[j];
				if(b[j]==1){
					p=1;
				}
				if(num==k && p==0){
					ans++;
					b[j]=1;
					pp=j;
					p=1;
				}
			}
			for(int j=i;j<=pp;j++){
				b[j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
