#include<bits/stdc++.h>
using namespace std;

string a,b;
struct M{
	string x,y;
}s[200005];
bool cmp(M X,M Y){
	return X.x.size()>Y.x.size();
}
long long n,q,B[200005],_,k;

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++) cin>>s[i].x>>s[i].y;
	_=s[1].x.size();
	B[_]=1;
	for(int i=2; i<=n; i++){
		if(s[i].x.size()!=_){
			for(int j=_-1;j>=s[i].x.size();j--) B[j]=B[_]+1;
		}
	}
	for(int i=1; i<=q; i++) {
		cin>>a>>b;
		k=0;
		if(a.size()!=b.size()) {
			cout<<0<<endl;
			continue;
		} int l=0,r=0;
		for(int j=0;j<a.size();j++) 
			if(a[j]!=b[j]){
				if(l==0) l=j;
				r=j;
			}
		for(int j=1;j<=r-l+1;j++){
			int r1=a.find(s[j].x),r2=b.find(s[j].y);
			if(r1+s[j].x.size()>r||r2+s[j].y.size()>r) continue;
			else{
				if(r1<l){
					while(r1<l&&r1!=-1) r1=a.find(s[j].x,r1+1);
					if(r1+s[j].x.size()>r) continue;
				}
				if(r2<l){
					while(r2<l&&r2!=-1) r2=a.find(s[j].y,r2+1);
					if(r2+s[j].y.size()>r) continue;
				} if(r1==r2) k++;
			}
		} cout<<k<<endl;
	}
	return 0;
}
