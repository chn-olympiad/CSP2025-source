#include<bits/stdc++.h>
using namespace std;

const int N=500005;

int n,K,ans;
int a[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>K;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int he=0;
			for(int k=i;k<=j;k++)
				he^=a[k];
			if(he==K){
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
