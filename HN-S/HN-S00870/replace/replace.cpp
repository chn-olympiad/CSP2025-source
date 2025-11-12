#include<bits/stdc++.h>
using namespace std;
string s1,s2,x,y;
int maxn=INT_MIN,cnt;
int main(){
	freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1>>s2;
	for(int j=1;j<=q;j++){
		cin>>x>>y;
		int len;
		if(x.size()>y.size()) len=x.size();
		else len=y.size();
		for(int i=0;i<len;i++){
			if(x[i]==y[i]) cnt++;
			if(x[i]!=y[i]){
				maxn=max(maxn,cnt);
				cnt=0;
			}
		}
		cout<<maxn<<endl;
		maxn=0;
		cnt=0;
	}
	return 0;
}
