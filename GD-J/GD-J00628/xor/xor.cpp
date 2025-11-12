#include<bits/stdc++.h>
using namespace std;
int a[100010],s[100010],d[100010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	cin>>a[1];
	s[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	int cnt=0,l=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if(j==1){
				if((s[j-1]^s[i])==k&&j>l){
					cnt++;
					l=i;
				}	
			}else{
				if((s[j-1]^s[i])==k&&j>l){
					cnt++;
					l=i;
					break;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
} 
