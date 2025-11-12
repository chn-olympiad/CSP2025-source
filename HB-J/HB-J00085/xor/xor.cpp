#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int N=5e5+100;
LL n,k,a[N],sum[N]={0},r[N],ans=0,f=1,ls=0,nxt[N];
bool kkk=1,vis[N]={0};

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int x=1;x<=n;x++){
		cin>>a[x];
		sum[x]=(sum[x-1]^a[x]);
		//printf("%d ",sum[x]);
		r[x]=x;
		nxt[x]=n+1;
	}
	//cout<<endl;
	while(f<=n){
		//cout<<endl<<f<<endl;
		kkk=1;
		for(int i=1;i<=n;){
			//cout<<i<<" ";
			if(vis[i]){
				i=r[i];
			}else{
				if(k==(sum[i+f-1]^sum[i-1]) && i+f-1<=nxt[i]){
					//printf("check %d %d\n",i,i+f-1);
					ans++;
					for(int o=i-1;o>=0;o--){
						if(vis[o]==0){
							nxt[o]=min((nxt[o]),i-1*1ll);
							//break;
						}else{
							break;
						}
					}
					ls+=f;
					kkk=1;
					vis[i]=1;
					r[i]=i+f;
					i=r[i];
				}else{
					i++;
				}
			}
		}
		f++;
		if(f>n){
			break;
		}
	}
	cout<<ans;
	return 0;
}

/*
4 3
2 1 0 3

4 0
2 1 0 3
*/
