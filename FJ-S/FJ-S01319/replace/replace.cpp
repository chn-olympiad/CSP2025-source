#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int N=2e5+5;
string s1[N],s2[N],sums[N];
int a[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	string sss="yusgeffg",ssss="ff";
//	cout<<sss.find(ssss);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i],a[i]=s1[i].size();
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		sums[0]="";
		int m=t1.size(),ans=0,l=0,r=0;
		for(int i=0;i<m;i++) sums[i+1]=sums[i]+t1[i];
		string dif_S="",nd=" ";
		for(int i=0;i<m;i++)
			if(t1[i]!=t2[i]){
				l=i;
				break;
			}
		for(int i=m-1;i>=0;i--)
			if(t1[i]==t2[i]) r=i-1;
			else break;
//		cout<<l+1<<' '<<r+1<<'\n';
		for(int i=l;i<=r;i++) dif_S+=t1[i],nd+=t2[i];
		for(int i=1;i<=n;i++){
			if(s1[i].find(dif_S)==string::npos) continue;
			if(t1.find(s1[i])==string::npos) continue;
			string c=s1[i],tot="";
			for(int j=0;j<m;j++){
				auto x=t1.find(c,j);
				tot=sums[x];
				j=x;
				if(x==string::npos) break;
//				for(int k=x;k<=x+a[i]-1;k++) 
				string rs=tot+s2[i];
//				cout<<s2[i]<<'\n';
				for(int k=x+a[i];k<m;k++) rs+=t1[k];
//				cout<<rs<<'\n';
				ans+=(rs==t2);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}


