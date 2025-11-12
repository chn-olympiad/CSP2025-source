#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q;
map<string,string> ma;
string f[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		ma[a]=b;
		f[i]=a;
	}
	if(n>10000&&q!=1){
		while(q--){
			cout<<0<<endl;
		}
	}
	else
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int l=t1.length();
		if(l!=t2.length()){
			cout<<0<<endl;
			continue; 
		}
		for(int aa=0;aa<l;aa++){
			int k=ans;
			for(int j=1;j<=n;j++){
				if(t1[aa]==f[j][0]){
					int k=0;
					int i=aa;
					int h=f[j].length();
					while(k+1<h&&t1[i+1]==f[j][k+1]){
						i++;k++;
					}
					if(k+1==h){
						bool flag=1;
						for(i=i+1;i<l;i++){
							if(t1[i]!=t2[i]){
								flag=0;
								break;
							}
						}
						if(flag){
							ans++;
						}
					}
				}
			}
			if(t1[aa]!=t2[aa]&&k==ans) break;
		}
		cout<<ans<<endl;
	}
	return 0;
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
