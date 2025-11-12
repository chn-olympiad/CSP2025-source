#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,k,ans=0,fl=1;
int a[maxn],y[maxn];
bool f[maxn]={};

int dfs(int l,int r,bool o){
	int re=0;
	if(o==0){
		for(int i=l;i<=r;i++){
			if(a[i]==k){
				fll++;
				re+=1+dfs(y[i-1]+1,y[i]-1,1);
				cout<<y[i-1]+1<<y[i]-1<<" ";
			}
		}
		re+=dfs(y[fl-1]+1,r,1);
		return re;
	}
	
	if(l>=r){
		return 0;
	}
	int ll,rr,sizm=1e9;
	for(int i=l;i<r;i++){
		int tem=l,siz=2;
		for(int j=l+1;j<r;j++){
			tem=tem^j;
			siz++;
			if(tem==k){
				if(siz<sizm){
					ll=i;
					rr=j;
					sizm=siz;
				}
				break;
			}
		}
		re=1+dfs(l,ll-1,1)+dfs(rr+1,r,1);
	}
	return re;
} 

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]==k){
    		y[fl]=i;
    		fl++;
		}
	}
	y[0]=0;
	ans=dfs(1,n,0);
	cout<<ans;
    return 0;
}

