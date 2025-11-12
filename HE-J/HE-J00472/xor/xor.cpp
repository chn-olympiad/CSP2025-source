#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans=0,sum=0,flag[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) ans++;
	}
	if(ans==n)
	cout<<n/2;
	else if(ans!=n){
		if(m==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0) sum++;
				if(a[i]==1&&flag[i]==0&&a[i+1]==1&&i+1<=n){
					flag[i+1]=1; sum++;
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==1) sum++;
			}
		}
		cout<<sum;
	}
	return 0;
} 
