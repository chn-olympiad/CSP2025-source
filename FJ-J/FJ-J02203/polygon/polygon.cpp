#include <bits/stdc++.h>
using namespace std;
int n,ans,p;
int l[5005];
bool book[5005];
					  
void m(int k,int v,int y,int o,int r){
	if(y>v){
		if(o>p){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	for(int i=r;i<=k;i++){
		if(!book[i]){
			book[i]=true;
			o+=l[i];
			m(k,v,y+1,o,i);
			book[i]=false;
			o-=l[i];
		}
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>l[i];
	sort(l+1,l+n+1);
	for(int i=3;i<=n;i++){
		for(int j=i;j<=n;j++){
			p=l[j]*2;
			memset(book,false,sizeof(book));
			m(j-1,i-1,1,l[j],1);
		}
	}
	cout<<ans;
	return 0;
}
