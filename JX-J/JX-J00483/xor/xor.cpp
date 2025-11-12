#include<bits/stdc++.h>
using namespace std;
long long a[10005];
long long b[10005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,l=1,r=1,t=0,v=0,h=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		r=l+i-1;
		for(int j=l+1;j<=r;j++){
			t=2;
			v=0;
			for(int l=1;l<=h;l++){
				if(b[l]<=j-1&&j-1>=b[l]){
					v=1;
				}
			}
			if((a[j-1]&a[j])==k&&v==0){
				t++;
				b[h]=l;
				h++;
			}
		}
	}
	cout<<t;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
