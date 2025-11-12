#include <bits/stdc++.h>
using namespace std;
int n,m;
string t[200005],c[200005];
string x,y;
int ans;
int f;
int cnt;
string a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>c[i];
	}
	while(m--){
		cin>>x>>y;
		ans=0;
		int len=x.size();
		for(int i=1;i<=n;i++){
			int l=t[i].size();
			f=0;
			int fl=0;
			cnt=0;
			for(int j=0;j<len;j++){
				a=x;
				b=y;
				f=0;
				for(int k=j;k<j+l;k++){
					if(a[k]!=t[i][k-j]||b[k]!=c[i][k-j]){
						f=1;
						break;
					}
					a[k]=c[i][k-j];
				}
//				if(f==1&&fl==1) break;
				if(f==0&&a==y){
					ans++;
					break;
				} 
				
			}
//			if(f==0){
//				ans++;
//				cout<<t[i]<<' '<<c[i]<<endl;
//				break;
//			} 
		}
		cout<<ans<<endl;
	}
	return 0;
}

