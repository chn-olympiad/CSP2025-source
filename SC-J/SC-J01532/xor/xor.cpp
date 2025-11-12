#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,a[N],k,tot;
bool sg[N];
int add(int left,int right);
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(add(i,j)==k) tot++;
		}
	}
	printf("%d",tot);
	return 0;
}
int add(int left,int right){
	for(int i=left;i<=right;i++){
		if(sg[i]==true) return k+1;
	}
	int tot=a[left];
	sg[left]=true;
	for(int i=left+1;i<=right;i++){
		tot=tot^a[i];
		sg[i]=true;
	} 
	return tot;
}
