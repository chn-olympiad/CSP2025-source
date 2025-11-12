#include<bits/stdc++.h>
using namespace std;
int n,a[5001],maxn=-1,sumn;
void search(int i,int cnt){
	if(cnt>2*maxn){
		sumn++;
	}
	for(int j=i+1;j<=n;j++){
		maxn=max(maxn,a[j]);
		search(j,cnt+a[j]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		maxn=a[i];
		search(i,a[i]);
	}
	printf("%d",sumn);
	return 0;
}
