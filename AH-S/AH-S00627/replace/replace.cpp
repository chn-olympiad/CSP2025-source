#include<bits/stdc++.h>
using namespace std;
int n,q;
/*struct str{
	string a;
	string b;
};*/
string a[1005],b[1005];
//struct str st[1005];
string ti,tj;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.in","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
		//cin>>st[i].a;
		//cin>>st[i].b;
		cin>>a[i];
		cin>>b[i];
	}
	while(q--){
		cin>>ti>>tj;
		long long ans = 0;
		for(int i=1;i<=n;i++){
			//string h = st[i].a;
			int h = ti.size();
			h -= a[i].size();
			h++;
			for(int j=0;j<h;j++){
				if(ti.substr(j,a[i].size()) == a[i]){
					//cout<<1<<" "<<ti.substr(j,a[i].size())<<" "<<a[i]<<endl;
					//cout<<ti.substr(0,j)+b[i]+ti.substr(j+b[i].size())<<" "<<tj<<" "<<j<<endl;
					if(ti.substr(0,j)+b[i]+ti.substr(j+b[i].size()) == tj){
						ans++;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
    return 0;
}
