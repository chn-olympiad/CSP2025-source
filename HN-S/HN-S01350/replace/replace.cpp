#include <bits/stdc++.h>
#define N 200005
#define ull unsigned long long
using namespace std;
const int base=1331;
int n,q;
string a[N],b[N]; 
string t1[N],t2[N];
int cnt1,cnt2; 
ull hsa[2005];
ull hsb[2005];
ull mi[2005]; 
int lena[N],lenb[N];
ull hs[N];   
void sub1(){
	mi[0]=1;
	for(int i=1;i<=2002;++i){
		mi[i]=mi[i-1]*base;
	}
	for(int wich=1;wich<=n;++wich){
		string x=a[wich],y=b[wich];
		int lenx=x.length(),leny=y.length();
		lena[wich]=lenx; lenb[wich]=leny;
		x=" "+x; y=" "+y;
		ull nm=0;
		for(int i=1;i<=lenx;++i){
			nm=nm*base+x[i];
		}
		hsa[wich]=nm;
		nm=0;
		for(int i=1;i<=leny;++i){
			nm=nm*base+y[i];
		}
		hsb[wich]=nm;
	}
	for(int que=1;que<=q;++que){
		int ans=0;
		string x=t1[que],y=t2[que];
		int lenx=x.length(),leny=y.length();
		x=" "+x; y=" "+y;
		for(int i=1;i<=lenx;++i){
			hs[i]=hs[i-1]*base+((int)x[i]);
		}
		ull res=0;
		for(int i=1;i<=leny;++i){
			res=res*base+((int)y[i]); 
		}
//		cerr<<"res : "<<res<<'\n'; 
		for(int i=1;i<=n;++i){
			for(int j=1;j<=lenx-lena[i]+1;++j){
				ull nm=hs[j+lena[i]-1]/mi[j-1];
				ull bian=0;
//				cerr<<nm<<" "<<hsa[i]<<" "<<hs[lenx]<<"\n";
				if(nm == hsa[i]){
//					cerr<<i<<'\n'; 
					bian=hs[lenx]-(nm*mi[j-1])+hsb[i]*mi[j-1];
				}
				if(bian == res){
					ans++;
				}
			}
//			cerr<<"-----"<<'\n'; 
		}
		cout<<ans<<'\n'; 
	}
	return ;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
		cnt1+=a[i].length();
		cnt1+=b[i].length(); 
	}
	for(int i=1;i<=q;++i){
		cin>>t1[i]>>t2[i];
		cnt2+=t1[i].length()+t2[i].length(); 
	}
	sub1();
	return 0;
}
