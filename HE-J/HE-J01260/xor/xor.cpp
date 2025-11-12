#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],x=1,y=1,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1&&x==1) x=1;
		else x=0;
		if(a[i]<=1&&y==1) y=1;
		else y=0;
	}
	if(k==0&&x==1) cout<<n/2;
	else if(k<=1&&y==1){
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
			cout<<ans;
		}
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				else if(a[i]==1&&a[i+1]==1) ans++,i++;
			}
			cout<<ans;
		}
	}
    fclose(stdin);
	fclose(stdout);
	return 0;
}
