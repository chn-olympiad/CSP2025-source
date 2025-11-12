#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,num=0;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		num=a[i];
		for(int j=1;i<n;i++){
			if(num==k){
				ans++;
				num=a[j+1];
			}
			else{
				num^=a[j];
			}
		}
	}
	printf("%d",ans);
	return 0;
}
