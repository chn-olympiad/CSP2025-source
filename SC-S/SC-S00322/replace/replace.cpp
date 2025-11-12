#include<bits/stdc++.h>
using namespace std;
const long long maxn=2e5+10;
string a,b;
string x[maxn],y[maxn];
long long n,q,ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	} 
	while(q--){
		ans=0;
		cin>>a>>b;
		for(int i=1;i<=n;i++){
			if(a.find(x[i])==b.find(y[i]) && a.find(x[i])!=string::npos){
				int pos=a.find(x[i]);
				string c=a;
				long long xiaobiao=0;
				for(int j=pos;j<=(pos+y[i].size()-1);j++){
					c[j]=y[i][xiaobiao];
					xiaobiao++;
				}
				if(c==b) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 