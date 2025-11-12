#include<bits/stdc++.h>
using namespace std;
int n,a[500005],k,b[2];
bool v[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0){
			b[0]++;
		}
		if(a[i]==1){
			b[1]++;
		}
	}
	if(b[1]==n){
		cout<<n/2;
	}else if(b[0]+b[1]==n){
		if(k==0){
			int s=b[0];
			for(int i=2;i<=n;i++){
				if(a[i-1]==1&&a[i]==1&&v[i-1]==false){
					s++;
					v[i-1]=true;
					v[i]=true;
				}
			} 
		}else if(k==1){
			cout<<b[1];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
