#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s=0;
	cin>>n>>k;
	int a[n+10],b[n+10];
	cin>>a[1];
	b[0]=0;
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}
	int l=1;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			s++;
			l=i+1;
			continue;
		}
		for(int j=l;j<i;j++){
			int x=b[i]^b[j-1];
			if(x==k){
				s++;
				l=i+1;
				break;
			}
		}
	}
	cout<<s;
	return 0;
}
