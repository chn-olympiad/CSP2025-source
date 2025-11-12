#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500100],s[500100],f[500100],has[1001000];
struct Node{
	int idx,x;
}x[1001000];
bool cmp(Node a,Node b){
	if(a.x!=b.x)return a.x<b.x;
	else return a.idx<b.idx;
}
bool cmp2(Node a,Node b){
	return a.idx<b.idx;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i <= n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	if(n<=5000){
		int ans=0;
		for(int i=1;i <= n;i++){
			//bool ff=1;
			for(int j=i-1;j >= 0;j--){
				if((s[i]^s[j])==k){
					f[i]=max(f[i],f[j]+1);
					//cout<<j<<" ";
					break;
				}
			}
			//if(ff) cout<<-1<<' ';
			f[i]=max(f[i-1],f[i]);
			//cout<<f[i]<<' ';
			ans=max(ans,f[i]);
		}
		cout<<ans;
	}else{
		for(int i=1;i <= n;i++){
			x[2*i-1]={2*i-1,s[i]};
			x[2*i]={2*i,s[i]^k};
		}
		sort(x+1,x+2*n+1,cmp);
		//x[0].x=-1;
		int y=-1,yy=-1,ss=0;
		for(int i=1;i <= 2*n;i++){
			//cout<<x[i].x<<' '<<x[i].idx<<'\n';
			if(x[i].x!=x[i-1].x){
				ss++;
				y=-1;
				yy=-1;
			}
			if((x[i].idx&1)){
				yy=y;
				y=(x[i].idx>>1)+1;
			}else{
					if(y!=(x[i].idx>>1))has[x[i].idx>>1]=y;
					else has[x[i].idx>>1]=yy;
					//cout<<(x[i].idx>>1)<<' '<<has[x[i].idx>>1]<<"\n";
			}
			
		}
		sort(x+1,x+2*n+1,cmp2);
		int ans=0;
		for(int i=1;i <= n;i++){
			if(has[i]!=-1)f[i]=f[has[i]]+1;
			else if(s[i]==k) f[i]=f[0]+1;
			//cout<<has[i]<<' ';
			f[i]=max(f[i-1],f[i]);
			//cout<<f[i]<<' ';
			ans=max(ans,f[i]);
		}
		cout<<ans;
	}
	return 0;
}
