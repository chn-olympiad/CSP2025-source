#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
int n,q;
struct as{
	string s,ss;
}a[1000010];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].ss;
	}
	while(q--){
		string x,y;
		cin>>x>>y;
		int sum=0;
		int l=0,r=0;
		for(int k=0;x[k];k++){
			l=k;
			string s;
			s=x[l];
			for(int i=k+1;x[i];i++){
				r=i;
				s=s+x[i];
				for(int j=1;j<=n;j++){
					string v;
					if(a[j].s==s){
						for(int ll=0;ll<k;ll++){
							v+=x[ll];
						}
						v+=a[j].ss;
						for(int ll=r+1;x[ll];ll++){
							v+=x[ll];
						}
						if(v==y){
							sum++;
						}
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
 
