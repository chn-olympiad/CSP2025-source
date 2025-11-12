#include<bits/stdc++.h>
using namespace std;
int n,q;
string strg[200005],strg2[200005];
string a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","r",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> strg[i]>>strg2[i];
	}
	for(int i=1;i<=q;i++){
		cin >>a >> b;
		int ans=0;
		for(int j=1;j<=n;j++){
			int k=strg[j].size();
			for(int l=0;l<a.size()-k+1;l++){
				if(a.substr(l,k)==strg[j]){
					string temp=a;
					for(int m=l;m<=l+k-1;m++){
						temp[m]=strg2[j][m-l];
					} 
					if(temp==b){
						ans++;
					}
				}
			}
		}
		cout << ans;
	}
	return 0;
} 

