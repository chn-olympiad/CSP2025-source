#include<bits/stdc++.h>
using namespace std;
struct t{
	int l,r;
}aa[100100];
struct tt{
	int r,ans;
};
int a[100100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int cntt=1;
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int l=i;l<=n;l++){
			cnt^=a[l];
			if(cnt==k){
				aa[cntt].l =i;
				aa[cntt].r =l;
				cntt++;
			}
		}
	}
	int maxx=0;
	cntt--;
	queue <tt> q;
	q.push({0,0});
	while(!q.empty()){
		tt z=q.front();
		q.pop();
		for(int i=1;i<=cntt;i++){
			if(aa[i].l >z.r ){
				maxx=max(maxx,z.ans +1);
				q.push({aa[i].r ,z.ans +1});
			}
		}
	}
	printf("%d",maxx);
	return 0;
}
