#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[(int)5e5+7];
int main(){
	freopen("xor6.in","r",stdin);
	freopen("xor6.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int jg=a[i];
			for(int k=i+1;k<=j;k++){
				jg=jg^a[k];
			}
			if(jg==m){
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
	}

