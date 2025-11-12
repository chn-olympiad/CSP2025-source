#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,T,maxn,minn=1e9;
string a[N],b[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>T;
	for(int k=1;k<=n;k++){
		cin>>a[k]>>b[k];
		int len=a[k].size();
		maxn=max(maxn,len);
		minn=min(minn,len);
	}
	while(T--){
		string x,y;
		cin>>x>>y;
		int len=x.size(),len2=y.size();
		if(len!=len2 || len<minn){
			puts("0");
			continue;
		}
		int l=0,r=0;
		for(int i=0;i<len;i++){
			if(x[i]!=y[i]){
				l=i;
				break;
			}
		}
		for(int i=len-1;i>=0;i--){
			if(x[i]!=y[i]) {
				r=i;
				break;
			}
		}
		int q=r-l+1;
		if(q>maxn){
			puts("0");
			continue;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i].size()>=q) cnt++;
		}
	    cout<<cnt<<"\n";
	}
	return 0;
}