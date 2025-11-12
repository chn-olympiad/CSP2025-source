#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int c=0,sum=0,cnt=0,check=0;
	cin>>n>>k;
	int a[n+5];
	bool vis[n+5]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]!=1){
			check==1;
		}
	}
	if(k==0&&check==0){
		cout<<n/2;
		return 0; 
	}
	for(int i=0;i<n;i++){
		sum=0;
		for(int j=i;j<n;j++){
			int tempi=i;
			int tempj=j;
			c=tempi;
			
			while(c>=tempi&&c<=tempj&&vis[c]==0){
				sum=(sum^a[c]);
				if(sum==k){
					cnt++;
					break;
					
				}
				vis[c]=1;
				c++;
			}
		}
	}
	cout<<cnt;
	return 0;
	
} 
