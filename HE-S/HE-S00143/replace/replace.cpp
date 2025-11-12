#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
inline void write(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>10){
		write(x/10);
	}
	putchar(x%10+'0');
	return ;
}
int n,q; 
map  <pair<pair<long long,long long>,pair<long long,long long>>,int>  hs;
const long long h1=998244353;
const long long h2=1000000007;
pair<long long,long long> has(string x){
	long long res1=0;
	long long res2=0;
	for(int i=0;i<x.size();i++){
		res1*=128;
		res1%=h1;
		res2*=77;
		res2%=h2;
		int y=x[i];
		res1+=y;
		res2+=y;
	}
	return make_pair(res1,res2);
}
signed main(){
	freopen("replace.in","r",stdin);
//	freopen("replace3.in","r",stdin);
	freopen("replace.out","w",stdout);
//	for(int h1=10000000007;h1<=)
	n=read();
	q=read();
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
//		cout<<" "<<has(s1).first<<" "<<has(s1).second<<" "<<has(s2).first<<" "<<has(s2).second<<endl;
		hs[make_pair(has(s1),has(s2))]++;
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		int l=-1,r=-1;
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[j]){
				r=j;
				if(l<0){
					l=j;
				}
			}
		}
		int ans=0;
		for(int j=0;j<=l;j++){
			long long res11=0,res12=0;
			long long res21=0,res22=0;
			for(int k=j;k<s1.size();k++){
//				cout<<k<<" ";
				res11*=128;
				res11%=h1;
				res12*=77;
				res12%=h2;
				int y=s1[k];
//				cout<<char(y)<<" ";
				res11+=y;
				res12+=y;
				
				res21*=128;
				res21%=h1;
				res22*=77;
				res22%=h2;
				y=s2[k];
//				cout<<char(y)<<endl;
				res21+=y;
				res22+=y;
				if(k>=r){
//					cout<<res11<<" "<<res12<<" "<<res21<<" "<<res22<<endl;
					ans+=hs[make_pair(make_pair(res11,res12),make_pair(res21,res22))];
				}
			}
		}
		write(ans);
		putchar('\n');
	}
	
	return 0;
}
