#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[10000];
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int h;
	for(int i=1;i<=n;i++){
		int cnt=0,g=0;
		for(int j=i;j<=n;j++){
			if(cnt!=k){
				cnt=cnt+a[j];
				g++;
			}
		}
		if(g>h)h=g;
	}
	cout<<h;
}
