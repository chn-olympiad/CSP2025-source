#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],bj[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if((a[i]|a[j]==k)&&bj[i]==0&&bj[j]==0){
				bj[i]=1;
				bj[j]=1;
				ans++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}