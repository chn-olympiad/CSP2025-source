#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[500005],cnt=0;
void check(int l,int r){
	int ans=0;
	bool f=0;
	for(int i=l;i<=r;i++){
		if(b[i])break;
		ans=ans xor a[i];
		f=1;
	}
	if(ans==k&&f){
		for(int i=l;i<=r;i++)b[i]=1;
		cnt++;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(b,0,sizeof(b));
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			check(i,j);
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
