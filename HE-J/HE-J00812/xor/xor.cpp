#include<bits/stdc++.h>
using namespace std;
int n=1,m=1,k,x,y,z,a[500005],b[500005],dp,sum=0,flag=0x3fff;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j){
				dp=a[i];
			}
			else{
				x=dp^a[j];
				dp=x;
			}
			if(dp==k){
				b[j]=i;
				break;
			}
		}
	}
	int fin=0;
	for(int i=1;i<=n;i++){
		if(b[i]!=0 && b[i]>fin){
			fin=i;
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
