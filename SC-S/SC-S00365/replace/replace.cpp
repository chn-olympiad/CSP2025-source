#include<bits/stdc++.h>
using namespace std;
string a[200010],b[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		string x,y;
		cin>>x>>y;
		int ans=0;
		for(int k=0;k<x.length();k++){
			for(int j=1;j<=n;j++){
				if(a[j][0]==x[k]){
					string q=x,p=y;
					int t=0;
					for(int g=0;g<a[j].length();g++){
						if(x[k+g]!=a[j][g]){
							t=1;
							break;
						}
						q[k+g]=b[j][g];
					}
					if(t==0){
						for(int g=0;g<b[j].length();g++){
							if(y[k+g]!=b[j][g]){
								t=1;
								break;
							}
						}
					}
					if(t==0&&q==p){
						ans++;
					}
				} 
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}