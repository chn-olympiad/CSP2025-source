#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int MAXN=2e5+5;
const int P=13131;
int max_len;
int n,q,ans,reflect[MAXN];
string s[MAXN][2],t[2],x;
inline void reads(string &s){
	s="";
	char ch=getchar();
	while(ch==' '||ch=='\n'||ch=='\r'||ch=='\t')ch=getchar();
	while(ch!=' '&&ch!=EOF&&ch!='\n'&&ch!='\r'&&ch!='\t'){
		s+=ch;
		ch=getchar();
	}
}
ull Hashs(string s){
	int l=s.size();
	max_len=max(max_len,l);
	ull res=0;
	for(int i=0;i<l;i++){
		res=res*P+s[i];
	}
	return res;
}
struct node{
	int i;
	ull v;
	bool operator<(const node x)const{
		return v<x.v;
	}
}z[MAXN];
int find(ull x){
	int l=1,r=n,res=n+1;
	while(l<=r){
		int mid=((l+r)>>1);
		if(z[mid].v<=x){
			res=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return res;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		reads(s[i][0]),reads(s[i][1]);
		z[i].v=Hashs(s[i][0]);
		z[i].i=i;
	}
	sort(z+1,z+n+1);
	for(int i=1;i<=n;i++){
		reflect[z[i].i]=i;
	}
	while(q--){
		ans=0;
		reads(t[0]),reads(t[1]);
		int l=t[0].size();
		for(int i=0;i<l;i++){
			for(int len=1;len<=max_len&&len+i-1<l;len++){
				x=t[0].substr(i,len);
				int w=find(Hashs(x));
				for(int j=w;j<=n;j++){
					if(s[reflect[j]][0]==x){
						string now_s=t[0].substr(0,i)+s[reflect[j]][1];
						if(i+len<l)now_s+=t[0].substr(i+len,l-i-len);
						if(t[1]==now_s)ans++;
					}else break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
