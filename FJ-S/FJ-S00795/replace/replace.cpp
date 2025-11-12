#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string a[N],b[N];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	string f,f2;
	while(q--){
		cin>>f>>f2;
		string p=f;
		int ans=0;
		int len=f.size();
		for(int i=0;i<len;i++){
			
			for(int j=1;j<=n;j++){
				p=f;
				if(f[i]==a[j][0]){
					p[i]=b[j][0];
					if(len-i<a[j].size())continue;
					bool l=1;
					for(int k=1;k<a[j].size();k++){
						
						if(f[i+k]!=a[j][k]){
							l=0;
							break;
						}else p[i+k]=b[j][k];
					}
					if(l){
						bool q=1;
						for(int w=0;w<len;w++){
								if(p[w]!=f2[w]){
									q=0;
									break;
								}
						}//cout<<p<<'\n';
						if(q)ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
