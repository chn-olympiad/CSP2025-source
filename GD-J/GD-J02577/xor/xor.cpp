#include<bits/stdc++.h>
using namespace std;
int n,a[100005],k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	int f=1,f1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=0;
		if(a[i]!=1&&a[i]!=0)f=0; 
	}
	if(f){
		cout<<n/2;
		return 0;
	}
	if(f1){
		if(k=1){
			int sum;
			int b[100005]; 
			for(int i=1;i<=n;i++){
				if(a[i]==1)sum++;
				if(a[i]==0&&a[i+1]==0&&b[i]==0&&b[i+1]==0){
					sum++;
					b[i]=1;
					b[i+1]=1;
				}
			}
			cout<<sum;
		}else{
			int sum;
			int b[100005]; 
			for(int i=1;i<=n;i++){
				if(a[i]==0)sum++;
				if(a[i]==1&&a[i+1]==1&&b[i]==0&&b[i+1]==0){
					sum++;
					b[i]=1;
					b[i+1]=1;
				}
			}
			cout<<sum;
		}
	}
	return 0;
}	
