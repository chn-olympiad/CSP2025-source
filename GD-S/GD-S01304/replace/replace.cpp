#include<bits/stdc++.h>
#define N 5000100
using namespace std;
int nxt[N],n,q,geb[N],grb[N];
string ge[N],gr[N];

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>ge[i]>>gr[i];
		for(int j=0;j<(int)ge[i].size();j++){
			if(ge[i][j]=='b'){
				geb[i]=j;
				break;
			}
		}
		for(int j=0;j<(int)gr[i].size();j++){
			if(gr[i][j]=='b'){
				grb[i]=j;
				break;
			}
		}
	}
	if(q==1){
		for(int i=1;i<=q;i++){
			string ase,asr;
			int ans=0;
			cin>>ase>>asr;
//			int be=0;
//			int br=0;
//			for(int i=0;i<(int)ase.size();i++){
//				if(ase[i]=='b'){
//					be=i;
//					break;
//				}
//			}
//			for(int i=0;i<(int)asr.size();i++){
//				if(asr[i]=='b'){
//					br=i;
//					break;
//				}
//			}
			for(int i=1;i<=n;i++){
				if(ge[i].size()<=ase.size()){
//					if(geb[i]<=be&&ase.size()-be>=ge[i].size()-geb[i]){
//						ans+=((be+grb[i]-geb[i])==br);
//					}
					for(int j=0;j<=(int)(ase.size()-ge[i].size());j++){
						bool fg=1;
						for(int k=0;k<(int)ge[i].size();k++){
							if(ase[j+k]!=ge[i][k]){
								fg=0;
								break;
							}
						}
						if(fg){
							string now=ase;
							for(int k=0;k<(int)gr[i].size();k++){
								now[j+k]=gr[i][k];
							}
							if(now==asr){
								ans++;
							}
						}
					}
				}
			}
			cout<<ans<<'\n';
		}
	}else{
		for(int i=1;i<=q;i++){
			string ase,asr;
			int ans=0;
			cin>>ase>>asr;
			int be=0;
			int br=0;
			for(int i=0;i<(int)ase.size();i++){
				if(ase[i]=='b'){
					be=i;
					break;
				}
			}
			for(int i=0;i<(int)asr.size();i++){
				if(asr[i]=='b'){
					br=i;
					break;
				}
			}
			for(int i=1;i<=n;i++){
				if(ge[i].size()<=ase.size()){
					if(geb[i]<=be&&ase.size()-be>=ge[i].size()-geb[i]){
						ans+=((be+grb[i]-geb[i])==br);
					}
//					for(int j=0;j<=(int)(ase.size()-ge[i].size());j++){
//						bool fg=1;
//						for(int k=0;k<(int)ge[i].size();k++){
//							if(ase[j+k]!=ge[i][k]){
//								fg=0;
//								break;
//							}
//						}
//						if(fg){
//							string now=ase;
//							for(int k=0;k<(int)gr[i].size();k++){
//								now[j+k]=gr[i][k];
//							}
//							if(now==asr){
//								ans++;
//							}
//						}
//					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
