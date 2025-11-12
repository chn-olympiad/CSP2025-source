#include<bits/stdc++.h>
using namespace std;
int n,a[500005],b[500005],k,w=1,q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l,r;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			l=i;
			r=j;
			q=a[l];
			for(int z=l+1;z<=r;z++){
				q=q^a[z];
				b[w]=q;
				w++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		b[i+w]=a[i];
	}
	int s=0;
	for(int i=1;i<=w+n;i++){
		if(b[i]==k){
			s++;
		}
	}
	cout<<s;
	return 0;
}
