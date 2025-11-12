#include<bits/stdc++.h>
using namespace std;
int n,maxx=-1,k;
int a[100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	if(a[0]^a[1]==k){
		if(a[0]>a[1])cout<<a[0];
		else cout<<a[1];
		return 0;
	}
	if((a[0]^a[0]==k)&&(a[1]^a[1]==k))cout<<max(a[0],a[1]);
	return 0;
}
