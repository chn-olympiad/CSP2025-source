#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans=0;
bool b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]^=a[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			if(a[j+i]^=a[j-1]==k){
				bool l=true;
				for(int e=j;e<j+i;e++){
					if(b[e]){
						l=false;
						break;
					}
				}
				if(l){
					for(int e=j;e<j+i;e++)b[e]=true;
					ans++;
				}	
			}
		}
	}
	printf("%d\n",ans/2);
	return 0;
}