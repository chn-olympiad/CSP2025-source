#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
 unsigned long long base=131;
const unsigned long long p=172346378246398348;
const unsigned long long prime=132467;
int n,q;
string s1[N],s2[N],t1,t2;
//vector<unsigned long long>h1[N],h2[N],h3[N],h4[N];
//unsigned long long get_hash1(int i,string tmp){
//	unsigned long long ans=0;
//	for(int j=1;j<=tmp.length();++j){
//		h1[i][j]=((h1[i][j-1]*base%p+tmp[j-1])%p+prime)%p;
//	}
//	return ans;
//}
//unsigned long long query1(int i,int l,int r){
//	return h1[i][r]-h1[]
//}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i){
		cin>>s1[i]>>s2[i];
//		get_hash1(i,s1[i]);
	}
	for(int i=1;i<=q;++i){
		cin>>t1>>t2;
		int ans=0,leng=t1.length();
		for(int j=1;j<=n;++j){
			if(leng<s1[j].length())continue;
			int len=s1[j].length();
			char beg=s1[j][0];
			for(int k=0;k<leng;++k){
				if(beg==t1[k]){
					string calc=t1;
					bool ok=true;
					for(int l=0;l<len;++l){
						calc[l+k]=s2[j][l];
						if(t1[l+k]!=s1[j][l]){
							ok=false;
							break;
						}
					}
					if(ok){
						if(calc==t2){
							ans++;
							break;
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

