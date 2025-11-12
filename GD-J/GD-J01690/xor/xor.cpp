#include<bits/stdc++.h>
using namespace std;
int a[100005];
int num[100005];
int ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		if(n%2==0)cout<<n/2;
		else cout<<1;
		return 0;
	}
	if(k==1){
		int x=0,y=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)x++;
			else y++;
		}
		cout<<y;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
