#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1005];
bool b[1005];
int ans;
bool p(int x,int y){
	int z;
	for(int i=y;i<=x+y-1;i++){
		if(b[i]==1){
			return 0; 
		}
		if(i!=y){
			z=z^a[i];
		}
		else{
			z=a[i];
		}
	}
	if(z!=k){
		return 0;
	}
	else{
		for(int i=y;i<=x+y-1;i++){
			b[i]=1;
		}
	}
	
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==k){
			ans++;
			b[i]=1;
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n-i+1;){
			if(p(i,j)){
				ans++;
				j=j+i;
			}
			else{
				j++;
			}
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}