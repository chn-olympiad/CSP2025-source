#include<bits/stdc++.h>
using namespace std;
//Ö»»»Ò»´Î 
int n,q,ans;
string s[200005],c[200005];
inline void sol1(){
	while(--q){
		ans=0;
		string f,t;
		cin>>f>>t;
		if(f.size()!=t.size()){
			cout<<0<<endl;
			continue;
		}
		int d_s=-1,d_e=-1,d_l; 
		for(int i=0;i<f.size();++i){
			if(f[i]!=t[i]){
				d_e=i;
				if(d_s==-1)d_s=i;
			}
		}
		d_l=d_e-d_s+1;
		for(int i=1;i<=n;++i){
			int l=s[i].size();
			if(l>=d_l&&l<=f.size()){
				for(int j=d_s;j>=0&&j>=d_e-l;--j){
//					cout<<j<<f[j]<<' ';
					bool is=1;
					for(int g=0;g<l;++g){
						if(f[g+j]!=s[i][g]||t[g+j]!=c[i][g]){
							is=0;
							break;
						}
					}
					if(is){
						/*cout<<i<<' ',*/ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}	
}

int main(){
	freopen("replace.in","r",stdin); 
	freopen("replace.out","w",stdout); 
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>c[i];
	} 
//	for(int i=1;i<=n;i++)
//		cout<<s[i][0]<<' '<<s[i][1]<<endl;

	sol1();
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
