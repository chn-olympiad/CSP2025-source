#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q,maxl=0,minl=1e9+5;
	cin >> n >> q;
	vector<string> a(n+1),b(n+1);
	vector<string> qs_a(q+1),qs_b(q+1);
	
	for(int i=1;i<=n;i++){
		cin >> a[i] >> b[i];
//		maxl=max(a[i].size(),maxl);
//		minl=min(a[i].size(),minl);
	}
	for(int i=1;i<=q;i++){
		cin >> qs_a[i] >> qs_b[i];
	} 
	
	int ans=0;
	
	for(int i=1;i<=q;i++){
		
		for(int l=0;l<qs_a.size();l++){
			for(int r=l+1;r<qs_a.size();r++){
//				if(r-l+1>maxl || r-l+1<minl)continue;
				string x="",z="";
				string y="";
				for(int p=0;p<l;p++) x=x+qs_a[i][p];
				for(int p=r+1;p<qs_a.size();p++) z=z+qs_a[i][p];
				for(int p=l;p<=r;p++) y=y+qs_a[i][p];
				
				for(int p=1;p<=n;p++){
					if(y==a[p]){
						string y_b=b[p];
						if(x+y_b+z==qs_b[i]){
							ans++;
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
