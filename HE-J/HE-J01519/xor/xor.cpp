#include<bits/stdc++.h>
using namespace std;
int n,k;
int ans=0;
int a[500005],pre[500006];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1)
		pre[i]=pre[i-1]^a[i];
		else
		pre[i]=a[i];
	}
	bool flag=false;
	for(int l=1;l<=n;l){
		for(int r=l;r<=n;r++){
			if((pre[r]^pre[l-1])==k){
				flag=true;
				ans++;
				l=r+1;
			}
		}
		if(flag==false){
			l++;
		}
		flag=false;
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
