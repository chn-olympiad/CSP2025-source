#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+101;
ll T,n,a[N],b[N],c[N],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	¶à×éÑùÀý	 
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=1;i<=n;i++)cin >> a[i] >> b[i] >> c[i];
		for(int j=1;j<=ceil(n/3);j++){
			int ma=-1,mb=-1,mc=-1,mma,mmb,mmc,mai,mbi,mci,ai,bi,ci;
			for(int i=1;i<=n;i++){
				if(ma<a[i]){
					mai = ai,mma = ma;
					ai = i,ma = a[i];
				}if(mb<b[i]){
					mbi = bi,mmb = mb;
					bi = i,mb = b[i];
				}if(mc<c[i]){
					mci = ci,mmc = mc;
					ci = i,mc = c[i];
				}
			}if(ai==bi){
				if(ma>mb){
					bi=mbi,mb=mmb;	
				}
				else ai=mai,ma=mma;
			}if(ai==ci){
				if(ma>mc)mc=0,mc = mmc;
				else ai=0,ma = mma;
			}if(ci==bi){
				if(mc>mb)bi=mbi,mb = mmb;
				else ci=mci,mc = mmc;
			}a[ai]=b[ai]=c[ai]=a[bi]=a[ci]=b[bi]=c[ci]=b[ci]=0;
			ans+=ma,ans+=mb,ans+=mc;
		}cout <<ans;
	}
	return 0;
} 
