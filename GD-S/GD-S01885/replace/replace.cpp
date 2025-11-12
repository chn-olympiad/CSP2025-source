#include<bits/stdc++.h>
using namespace std;
const int N=100005;
string a[N],b[N],ll[N],lp[N];
string tt,yy;
int main(){
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	string ty;
	int ans,po,ts=0;
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>ll[i]>>lp[i];
		yy=ll[i];
		tt=lp[i];
		for(int j=1;j<=n;j++){
			ts=0;
			po=yy.find(a[j]);
			
			ty=b[j];
			for(int k=0;k<a[j].size();po++,k++){
				yy[po]=ty[k];
			}
			if(yy==tt){
				ans++;
			}
		}
		
		cout<<ans<<endl;
	}
	return 0;
} 
