#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],pd[5005],jz[5005][5005];
long long cnt,maxlengh,maxmaxx,p;
void dg(long long maxx,long long lengh){
	if(lengh>=maxlengh){
		return;
	}
	if(jz[maxx][lengh]==1){
		return ;
	}
	if(p>=3&&lengh>2*maxx){
		jz[maxx][lengh]=1;
	}
	for(int i=1;i<=n;i++){
		if(pd[i]!=1){
			pd[i]=1;
			p++;
			dg(max(maxx,a[i]),(lengh+a[i]));
			p--;
			pd[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxlengh+=a[i];
		maxmaxx=max(maxmaxx,a[i]);
	}
	for(int i=1;i<=n;i++){
		pd[i]=1;
		p=1;
		dg(a[i],a[i]);
		p=0;
		pd[i]=0;
	}
	for(int i=1;i<=maxmaxx;i++){
		for(int j=1;j<=maxlengh;j++){
			if(jz[i][j]){
				cnt++;
				cout<<i<<" "<<j<<endl;
			}
		}
	}
	cout<<cnt;
}
