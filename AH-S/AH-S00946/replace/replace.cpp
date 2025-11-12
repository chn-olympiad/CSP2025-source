#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[100005],c[100005],x,y,xx,xxx;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>c[i];
	}
	if(n<=100||q==1){
		while(q--){
			cin>>x>>y;
			int ans=0;
			for(int i=1;i<=n;i++){
				xx=x;xxx=x;
				int k=xxx.find(s[i]);
	//			cout<<k<<"\n";
				while(k!=-1){
					xx=x;
					for(int j=k;j<k+s[i].size();j++){
						xxx[j]=c[i][j-k];
						xx[j]=c[i][j-k];
					}
	//				cout<<xx<<"\n";
					if(xx==y)ans++;
					k=xxx.find(s[i]);
				}
			}
			cout<<ans<<"\n";
		}
	}
	else{
		while(q--)cout<<0<<"\n";
	}
	return 0;
}
