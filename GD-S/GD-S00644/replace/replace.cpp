#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
string a[N],b[N],x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;i++) cin >> a[i] >> b[i];
	while(q--){
		int ans=0,f1=0,b1,b2;
		cin >> x >> y;
		int len=x.size();
		for(int i=0;i<len;i++){
			if(x[i]=='b') b1=i;
			if(y[i]=='b') b2=i;
		}
		f1=b1-b2;
		for(int i=1;i<=n;i++){
			int m=a[i].size(),l,r,f2=0;
			for(int j=0;j<m;j++){
				if(a[i][j]=='b') l=j;
				if(b[i][j]=='b') r=j;
			}
			f2=l-r;
			bool flag=1;
			if(l>b1||m-r>len-b2) flag=0;
			if(f1==f2&&m<=len&&flag) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
