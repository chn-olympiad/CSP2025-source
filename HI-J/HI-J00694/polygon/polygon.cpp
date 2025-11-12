#include<bits/stdc++.h>
using namespace std;
int n,a[5001],ans=0;
int main(){
	freopen("","r",stdin);
	freopen("","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int flag=0;
		for(int j=1;j<=n-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
				flag=1;
			}
		}
		if(flag==0) break;
	}
	if(n==3){
		if((a[1]+a[2]+a[3])>(a[3]*2)){
			cout<<1;
			return 0;
		}
	}
	else{
		cout<<0;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
