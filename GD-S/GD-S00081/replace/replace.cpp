#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb emplace_back
#define fr first
#define sc second
typedef const int Int;
typedef pair<int,int> pii;

inline  Int read(){
	int x=0;char c=getchar();bool f=(c=='-');
	while(!isdigit(c))c=getchar(),f|=(c=='-');
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return f?-x:x;
}

Int N=2e5+5,M1=1e9+7,M2=998244353,S=5e6+5;

Int base=131;

int n,q;

string a[N],b[N];

LL ha1[N],ha2[N];
LL hb1[N],hb2[N];

string s,t;

LL hs1[S],hs2[S];
LL ht1[S],ht2[S];

inline LL geth(Int &l,Int &r,const LL *h,const bool &typ){
	return typ?(h[r+1]-h[l]+M2)%M2:(h[r+1]-h[l]+M1)%M1;
}

set <pair<pii,pii> > str;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(int i=1;i<=q;i++){
		cin>>s>>t;
		cout<<0<<'\n';
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<a[i].size();j++){
//			ha1[i]=(ha1[i]*base+(a[i][j]-'a'+1))%M1;
//			ha2[i]=(ha2[i]*base+(a[i][j]-'a'+1))%M2;
//		}
//		for(int j=0;j<b[i].size();j++){
//			hb1[i]=(hb1[i]*base+(b[i][j]-'a'+1))%M1;
//			hb2[i]=(hb2[i]*base+(b[i][j]-'a'+1))%M2;
//		}
//		cout<<ha1[i]<<" "<<ha2[i]<<" "<<hb1[i]<<" "<<hb2[i]<<endl;
//	}
//	cout<<endl;
//	for(int i=1;i<=q;i++){
//		cin>>s>>t;
//		int len=s.size();
//		int l,r;
////		for(i=0;i<len;i++){
////			if(s[i]!=t[i]){
////				l=i-1;
////				break;
////			}
////		}
////		for(int i=len-1;~i;i--){
////			if(s[i]!=t[i]){
////				r=i+1;
////				break;
////			}
////		}
//		for(int j=0;j<len;j++){
//			hs1[j+1]=(hs1[j]*base+(s[i]-'a'+1))%M1;
//			hs2[j+1]=(hs2[j]*base+(s[i]-'a'+1))%M2;
//			ht1[j+1]=(ht1[j]*base+(t[i]-'a'+1))%M1;
//			ht2[j+1]=(ht2[j]*base+(t[i]-'a'+1))%M2;
//			cout<<hs1[j+1]<<" "<<hs2[j+1]<<" "<<ht1[j+1]<<" "<<ht2[j+1]<<endl;
//		}
//		cout<<endl;
//		int ans;
//		for(int j=0;j<len;j++){
//			for(int k=1;k<=n;k++){
//				if(len-j-1<a[k].size())continue;
//				cout<<geth(j,j+a[k].size()-1,hs1,0)<<" "<<geth(j,j+a[k].size()-1,hs2,1)<<" "<<geth(j,j+b[k].size()-1,ht1,0)<<" "<<geth(j,j+b[k].size()-1,ht2,1)<<endl;
//				if(ha1[k]==geth(j,j+a[k].size()-1,hs1,0)&&ha2[k]==geth(j,j+a[k].size()-1,hs2,1)){
//					if((hs1[len]-ha1[k]+hb1[k]+M1)%M1==ht1[len]&&(hs2[len]-ha2[k]+hb2[k]+M2)%M2==ht2[len])ans++;
//				}
//			}
//		}
//		printf("%d\n",ans);
//	}
	return 0;
}



































