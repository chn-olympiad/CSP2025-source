#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],b[100005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		int l=i+1,c=a[i];
		bool bl=0;
		if(c==k)
			bl=1,l=i,ans++;
		else while(l<=n){
			c=(c)xor(a[l]);
			l++;
			if(c==k){
				bl=1;
				ans++;
				break;
			}
		}
		if(bl==1)
			for(int j=i;j<=l;j++)b[j]++;
	}
	for(int i=1;i<=n;i++){
		if(b[i]>1){
			int c=a[i],l=i+1;
			while(l<=n){
				c=(c)xor(a[l]);
				l++;
				if(c==k){
					break;
				}
			}
			if(a[i]==k)l=i;
			for(int j=i;j<=l;j++)b[j]--;
			ans--;
		}
	}
	cout<<ans;
	return 0;
} 
