#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[50001];
ll k,cnt,sum;
signed main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int b=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum=a[i];
			for(int k=i+1;k<=j;k++){
				sum^=a[k];
			}
			if(sum==k){
				cnt++;
				b=j;
				break; 
			}
		}
		i=b;
	}
	cout<<cnt;
	fclose(stdin);
  	fclose(stdout);
}
