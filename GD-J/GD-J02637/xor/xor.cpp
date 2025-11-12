#include<bits/stdc++.h>
using namespace std;
int a[500010],c[500010]; 
int l,r,len;
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=a[i-1]^x;
		c[i]=x; 
	}
	int cnt=0,q=0;
	for(int i=1;i<=n;i++){
		if((a[i]^a[q])==k&&c[i]!=0) cnt++,q=i;
		else if(c[i]==k) cnt++,q=i;
		else{
			for(int j=i-1;j>=q;j--){
				if((a[i]^a[j])==k){
					cnt++;
					q=j;
					break;
				}
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
