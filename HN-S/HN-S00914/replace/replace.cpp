#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string a[100],b[100];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		string c,d;
		cin>>c>>d;
		int ans=0;
		for(int i=0;i<n;i++){
			int e=0,j;
			for( j=0;j<c.size()-a[i].size()+1;j++){
				if(c[j]!=a[i][e]){
					e=0;
				}
				if(e&&c[j]==a[i][e]){
					e++;
				}
				if(c[j]==a[i][0]){
					e=1;
				}
				if(e==a[i].size()){
					int jj=j-e;
					string cc=c;
					for(;e>=0;e--){
						cc[jj+e]=b[i][e-1];
					}
					if(cc==d){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
