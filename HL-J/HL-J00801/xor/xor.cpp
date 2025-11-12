#include<bits/stdc++.h>
using namespace std;
int n,k,a[500050],b[500050][10000000000],sum2=0,ans=0,cmp=1,i;
bool f(int x,int y){
	if(x==0){
		return false;
	}
	while(true){
		if(b[y][cmp]==1 && b[y-1][cmp]==1){
			b[y][cmp]=0;
		}
		else{
			b[y][cmp]=1;
		}
		cmp++;
		if(b[0][cmp]!=b[y][cmp]){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("xor.in ","r",stdin);
	freopen("xor.out ","w",stdout);
	cin>>n>>k;
	int sum=k;
	while(sum>0){
		b[0][cmp]=sum%2;
		sum/2;
		cmp++;
	}
	cmp=0;
	for(i=1;i<=n;i++){
		cin>>a[i];
		sum=a[i];
		while(sum>0){
			b[i][cmp]=sum%2;
			sum/2;
			cmp++;
		}
		cmp=0;
	}
	for(int i=1;i<=n;i++){
		if(i==k){
			ans++;
			b[1][1]=0;
			sum2=0;
		}
		else{
			if(f(sum2,i)){
				ans++;
				sum2=0;
				b[i][1]=0;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
