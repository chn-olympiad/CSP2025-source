#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=1e6;
int ax[N],pre[N],cnt,ans;
struct s{
	int a,b,flag=0;
}bx[N];
//11:45
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>ax[i];
		if(i==1){
			pre[i]=ax[i];
		}else{
			pre[i]=pre[i-1]^ax[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(pre[j]^pre[i-1]==k){
				bx[++cnt].a=i;
				bx[cnt].b=j;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		if(bx[i].flag==1){
			continue;
		}
		for(int j=i+1;j<=cnt;j++){
			if(bx[j].flag==1){
				continue;
			}
			if(bx[j].a>=bx[i].a&&bx[j].a<=bx[i].b||bx[j].b>=bx[i].a&&bx[j].b<=bx[i].b){
				if(bx[i].b-bx[i].a>bx[j].b-bx[j].a){
					bx[j].flag=1;
				}else{
					bx[i].flag=1;
				}
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		if(bx[i].flag==0){
			 ans=max(ans,bx[i].b-bx[i].a);
		}
		
	}
	cout<<ans;
	return 0;
}