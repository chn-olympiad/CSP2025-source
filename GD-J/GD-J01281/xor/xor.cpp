#include<bits/stdc++.h>
using namespace std;
bool b[500500];
long long a[500500];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	long long c=0;
	for(int i=1;i<=n;i++){
		scanf("%ll",&a[i]);
		if(a[i]==k){
			c++;
			b[i]=1;
		}
	}
	for(int i=1;i<=n-1;i++){
		long long s=a[i];
		if(b[i]==1) continue;
		for(int j=i+1;j<=n;j++){
			if(b[j]==1){
				break;
			}
			s=s^a[j];
			if(s==k){
				i=j;
				c++;
				break;
			} 
		}
	}
	cout<<c;
	return 0;
} 
