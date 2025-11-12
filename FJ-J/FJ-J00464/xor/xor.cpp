#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010]={0},ans=-1;
void sb(int x,int y){
	if(x>n){
		y=0;
		int z,an=0;
		for(int i=1;i<=n;i++){
			if(b[i]==0){
				continue;
			}
			if(b[i]!=y){
				if(y!=0){
					if(z!=m){
						return;
					}
					else an++;
				}
				z=a[i];
				y=b[i];
			}
			else{
				z^=a[i];
			}
		}
		if(z!=m) return;
		else an++;
		ans=max(an,ans);
		return;
	}
	
	b[x]=y+1;
	sb(x+1,y+1);
	if(b[x]!=0) b[x]=y,sb(x+1,y);
	b[x]=0;
	sb(x+1,y);
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sb(1,1);
	cout<<ans;
}
