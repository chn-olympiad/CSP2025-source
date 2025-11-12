#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5+10;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int ret=0;
	int u=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int x=i+1;
			int num=a[i];
			while(x<=j){
				num=num^a[x];
				x++;
			}
			bool flag=true;
			if(num==k){
				ret++;
				i=j+1;
			}
		}
	}
	printf("%d",ret);
	return 0;
}