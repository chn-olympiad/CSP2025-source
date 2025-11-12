#include<bits/stdc++.h>
using namespace std;
int i,n,t,l,r,j,k,ans;
string x,y,l1,r1,x1,y1,x2,y2,x3,y3;
const int maxn=10001,maxm=1000001;
map<string,string>q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>t;
	cin.tie(0);
	for(i=1;i<=n;i++){
		cin>>x>>y;
		q[x]=y;
	}
	for(int ii=1;ii<=t&&ii<=1000;ii++){
		cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<0<<endl;
			continue;
		}
		int len=x.size();
		if(len>=5000){
			cout<<0<<endl;
			continue;
		}
		for(l=0;x[l]==y[l];l++)l1=l1+x[l];
		for(r=len-1;x[r]==y[r];r--)r1=x[r]+r1;
		ans=0;
		x1=y1="";
		for(k=l;k<=r;k++){
			x1=x1+x[k];
			y1=y1+y[k];
		}
		x2=x1;
		y2=y1;
		for(i=l;i>=0;i--){
			if(i!=l){
				x2=x[i]+x2;
				y2=y[i]+y2;
			}
			x3=x2;
			y3=y2;
			for(j=r;j<len;j++){
				if(j!=r){
					x3=x3+x[i];
					y3=y3+y[i];
				}
				if(q[x3]==y3)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
