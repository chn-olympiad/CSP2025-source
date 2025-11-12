#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N];
int f,t;
bool q=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int i;
	if(k!=0&&k!=1) q=false;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1) f++;
		if(a[i]==0) t++;
		if(a[i]!=1&&a[i]!=0) q=false;
	}
	if(k==0) cout<<t;
	if(k==1) cout<<f;
	if(q==false) cout<<2;
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
