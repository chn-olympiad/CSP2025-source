#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int a[N],b[N];
int n,ans,j;
bool flg(int xx){
	int ans=0;
	for(int i=1;i<=xx;i++){
		ans+=b[i];
	}
	if(ans>(2*b[xx])){
		return true;
	}else{
		return false;
	}
}
void app(int k,int i,int l){
	if(k==l){
		if(flg(l)){
			ans++;
		}
		return;
	}
	if(i>n){
	    return;
	}
	app(k,i+1,l);
	b[k+1]=a[i];
	app(k+1,i+1,l);
	b[k+1]=0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		app(0,1,i);
		memset(b,0,sizeof(b));
		j=0;
	}
	cout<<ans<<endl;
	return 0;
}
