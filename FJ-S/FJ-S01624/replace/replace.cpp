#include<bits/stdc++.h>
using namespace std;
int n,q,ans,ll[1000005],rr[1000005],ll1[1000005],rr1[1000005];
string a[200005],b[200005],x,y,xx="",yy="";
string sd(string xa,int l,int r){
	string t="";
	for(int i = l;i<=r;i++){
		t+=xa[i];
	}
	return t;
}
bool pd(string xa,string xb,int l,int r){
	for(int i = l;i<=r;i++){
		if(xa[i]!=xb[i])return false;
	}
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j = 0;j<a[i].size();j++){
			if(a[i][j]=='b'){
				ll[i]=j;
				ll1[i]=a[i].size()-j-1;
			}
			if(b[i][j]=='b'){
				rr[i]=j;
				rr1[i]=b[i].size()-j-1;
			}
		}
	}
	if(n<=100){
		for(int i = 1;i<=q;i++){
			ans=0;
			cin>>x>>y;
			for(int j = 0;j<x.size();j++){
				if(x[j]!=y[j]){
					xx+=x[j];
					yy+=y[j];
				}
			}
			
			for(int j = 1;j<=n;j++){
				for(int k = 0;k+a[j].size()-1<x.size();k++){
					if(pd(x,y,0,k-1)&&pd(x,y,k+a[j].size(),x.size()-1)){
						if(sd(x,k,k+a[j].size()-1)==a[j]&&sd(y,k,k+b[j].size()-1)==b[j]){
							ans++;
						}
					}
					
				}
			}
			cout<<ans<<endl;
		}
	}
	else{
		for(int i = 1;i<=q;i++){
			ans=0;
			int lll,rrr,lll1,rrr1;
			cin>>x>>y;
			for(int j = 0;j<x.size();j++){
				if(x[j]=='b'){
					lll=j;
					lll1=x.size()-j-1;
				}
				if(y[j]=='b'){
					rrr=j;
					rrr1=x.size()-j-1;
				}
			}
			int cha=lll-rrr;
			for(int j = 1;j<=n;j++){
				if(ll[j]-rr[j]==cha&&ll[j]<=lll&&rr[j]<=rrr&&ll1[j]<=lll1&&rr1[j]<=rrr1){
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
