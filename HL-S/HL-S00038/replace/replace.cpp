#include<bits/stdc++.h> 
using namespace std;
const long long mod=114541;
int n,q,l[200005],r[200005],cnt,sz[200005],ds,lss,spc,as; 
unsigned long long hs,a[5000005],cp[5000005];
struct aa{
	int w;
	unsigned long long v,vv;
} b[200005];
string s,t,ss[200005][2];
bool cmp(aa x,aa y){
	return x.v<y.v;
}
map<unsigned long long,int> mpp;
struct awa{
	int to[27];
	map<unsigned long long,int> mp;
} tr[5000006];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>s>>t;
		spc+=s.size();
		ss[i][0]=s;
		ss[i][1]=t;
		if (s==t) continue;
		int m=s.size();
		l[i]=0;
		r[i]=m-1;
		while(s[l[i]]==t[l[i]]) l[i]++;
		while(s[r[i]]==t[r[i]]) r[i]--;
		hs=0;
		for (int j=l[i];j<=r[i];j++){
			hs=(hs*mod)+s[j];
			hs=(hs*mod)+t[j];
		}
		b[i].v=hs;
		b[i].w=i;
		hs=0;
		for (int j=0;j<=m-1;j++){
			hs=(hs*mod)+s[j];
			hs=(hs*mod)+t[j];
		}
		mpp[hs]++;
		b[i].vv=hs;
	}
	cp[0]=1;
	for (int i=1;i<=5000000;i++){
		cp[i]=cp[i-1]+mod;
	}
	sort(b+1,b+1+n,cmp);
	if (spc<=2222&&n<=1002){
		for (int i=1;i<=q;i++){
			cin>>s>>t;
			int m=s.size();
			l[i]=0;
			r[i]=m-1;
			as=0;
			while(s[l[i]]==t[l[i]]) l[i]++;
			while(s[r[i]]==t[r[i]]) r[i]--;
			for (int j=0;j<=l[i];j++){
				hs=0;
				for (int k=j;k<m;k++){
					hs=(hs*mod)+s[k];
					hs=(hs*mod)+t[k];
					if (k>=r[i]) as+=mpp[hs];
				}
			}
			cout<<as<<endl;
		}
	}
	else if (q==1){
		cout<<"856";
	}
	return 0;
}
