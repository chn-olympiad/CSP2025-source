#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q; 
string s1[200010],s2[200010];
int ans=0;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//cin.tie(0)->sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		ans=0;
		for(int l=0;l<=t1.size();l++){
			for(int r=l+1;r<t1.size();r++){
				string x1,x2,y1,y2,z1,z2;
				for(int i=0;i<l;i++){
					x1+=t1[i],x2+=t2[i];
				}
				for(int i=l;i<=r;i++){
					y1+=t1[i],y2+=t2[i];
				}
				for(int i=r+1;i<=n;i++){
					z1+=t1[i],z2+=t2[i];
				}
				//cout<<0<<" "<<l<<" "<<r<<" "<<n<<endl;
				//cout<<x1<<" "<<y1<<" "<<z1<<"  "<<x2<<" "<<y2<<" "<<z2<<endl;
				if(x1==x2&&z1==z2){
					for(int i=1;i<=n;i++){
						if(y2==s2[i]&&y1==s1[i]){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
}

