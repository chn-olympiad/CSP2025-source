#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,ll1[N],ll2[N];
string ss1[N],ss2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	bool bl=true;
	for(int i=1;i<=n;i++){
		cin>>ss1[i]>>ss2[i];
		if(bl==true){
			int ff1=ss1[i].find('b');
			int ff2=ss2[i].find('b');
			if(ff1==-1||ff2==-1) bl=false;
			else{
				int sz=(int)(ss1[i].size());
				ll1[i]=ff1;
				ll2[i]=ff2;
			}
		}
	}
	while(q--){
		string tt1,tt2;
		cin>>tt1>>tt2;
		int FF1=tt1.find('b');
		int FF2=tt2.find('b');
		int SZ=(int)(tt1.size());
		int ans=0;
		if(n<=1000&&SZ<=2000||bl==false||FF1==-1||FF2==-1){
			int l=-1,r=-1;
			for(int i=0;i<tt1.size();i++){
				if(tt1[i]!=tt2[i]){
					if(l==-1) l=i;
					r=i;
				}
			}
			for(int i=1;i<=n;i++){
				int ff1=tt1.find(ss1[i]),ff2=tt2.find(ss2[i]);
				int sz=(int)(ss1[i].size());
				if(ff1!=-1&&ff1==ff2&&ff1<=l&&ff1+sz-1>=r){
					bool bll=true;
					for(int j=ff1;j<l;j++){
						if(ss1[i][j-ff1]!=tt1[j]){
							bll=false;
							break;
						}
					}
					if(bll==false) continue;
					for(int j=r+1;j<=ff1+sz-1;j++){
						if(ss1[i][j-ff1]!=tt1[j]){
							bll=false;
							break;
						}
					}
					if(bll==false) continue;
					ans++;
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				int sz=(int)(ss1[i].size());
				if(FF1-FF2==ll1[i]-ll2[i]&&FF1>=ll1[i]&&FF2>=ll2[i]&&SZ-FF1>=sz-ll1[i]&&SZ-FF2>=sz-ll2[i]){
					ans++;
				} 
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
