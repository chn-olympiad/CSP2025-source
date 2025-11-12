#include<bits/stdc++.h>
#define int unsigned long long
#define endl "\n"
using namespace std;
const int maxn=1e6+5,B=13131;
int n,q,val1[maxn],val2[maxn],pw[maxn];
int s1[maxn],s2[maxn],sz[maxn];
int get_hash1(int x,int y){
	return val1[y]-val1[x-1]*pw[y-x+1];
}
int get_hash2(int x,int y){
	return val2[y]-val2[x-1]*pw[y-x+1];
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		sz[i]=x.size();
		for(int j=1;j<=x.size();j++){
			s1[i]=s1[i]*B+x[j-1];
		}
		for(int j=1;j<=y.size();j++){
			s2[i]=s2[i]*B+y[j-1];
		}
	}
	pw[0]=1;
	for(int i=1;i<=1000005;i++){
		pw[i]=pw[i-1]*B;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int len1=t1.size(),len2=t2.size();
		t1=' '+t1;
		t2=' '+t2;
		for(int i=1;i<=len1;i++){
			val1[i]=val1[i-1]*B+t1[i];
		}
		for(int i=1;i<=len2;i++){
			val2[i]=val2[i-1]*B+t2[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j+sz[i]-1<=len1;j++){
				if(get_hash1(j,j+sz[i]-1)==s1[i]&&get_hash2(j,j+sz[i]-1)==s2[i]&&get_hash1(1,j-1)==get_hash2(1,j-1)&&get_hash1(j+sz[i],len1)==get_hash2(j+sz[i],len1)){
					ans++;
					continue;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
60pts
©³©©©©©©©©©©©©©©©· ©³©©©©©©©©©©©©©©©·          ©³©©©©©·                  ©³©©©©©·  
©«   ©³©©©©©·   ©« ©«   ©³©©©©©·   ©«          ©«    ©«                  ©«    ©«
©«   ©«    ©«   ©« ©«   ©«    ©«   ©«          ©«    ©«                  ©«    ©«
©«   ©»©©©©©¿   ©« ©«   ©»©©©©©¿   ©«  ©³©©©©©©©¿    ©»©©©©©©©·  ©³©©©©©©©¿    ©»©©©©©©©·
©«    ©²\    \©©©¿ ©«    ©²©©©©©©©©©¿  ©«                    ©«  ©«                    ©«
©«    ©« \    \    ©«    ©«            ©»©©©©©©©·    ©³©©©©©©©¿  ©»©©©©©©©·    ©³©©©©©©©¿
©«    ©«  \    \   ©«    ©«                    ©«    ©«                  ©«    ©«
©«    ©«   \    \  ©«    ©«                    ©«    ©«                  ©«    ©« 
©»©©©©©¿   ©»©©©©©¿©»©©©©©¿                    ©»©©©©©¿                  ©»©©©©©¿
*/
