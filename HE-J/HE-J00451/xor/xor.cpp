#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000001],l,r,sum=0;
int fun(int x,int y){
	int ans=a[x];
	for(int i=x+1;i<=y;i++){
		ans^=a[i];
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(l=1;l<=n;l++){
		for(r=l;r<=n;r++){
			if(fun(l,r)==k){
				sum++;
				l=r;
				break;
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
