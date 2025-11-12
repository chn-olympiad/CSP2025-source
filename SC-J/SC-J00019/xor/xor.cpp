#include<bits/stdc++.h>
using namespace std;
int n,k,cnt=0;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int l=1,r=1;
	while(r<=n){
		int num=0;
		for(int j=l;j<=r;j++)
			num^=a[j];
		if(num==k){
			cnt++;
			l=r+1;
			r=l;
			continue;
		}else{
			r++;
		}
	}cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}