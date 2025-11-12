#include<bits/stdc++.h>
#define int long long
#define qwq ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pii pair<int,int>
using namespace std;
const int N=2e5+10;
int n,q,fr[N],bk[N];
struct S{
	string x,y;
	bool operator<(const S &a)const{
		return x<a.x;
	}
}s[N];
struct node{
	int sum,id;
}p[N];
bool cmp(node a,node b){
	return a.sum<b.sum;
}
signed main(){
	qwq;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].x>>s[i].y;
		int len=s[i].x.size(),pos1,pos2;
		for(int j=0;j<len;j++){
			if(s[i].x[j]=='b')pos1=j;
			if(s[i].y[j]=='b')pos2=j;
		}
		fr[i]=pos1,bk[i]=len-pos1-1;
		p[i]={pos2-pos1,i};
	}
	sort(p+1,p+n+1,cmp);
	sort(s+1,s+n+1);
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		int len=t1.size();
		t1=' '+t1,t2=' '+t2;
		if(n<=1000&&q<=1000&&len<=2000){
			int l=0,r=0;
			for(int i=1;i<=len;i++){
				if(t1[i]!=t2[i]&&!l)l=i;
				if(t1[i]!=t2[i]){
					r=i;
				}
			}
	//		cout<<"Differelent from ";
	//		cout<<l<<" to "<<r<<"\len";
			string d1="",d2="";
			for(int i=l;i<=r;i++){
				d1+=t1[i];
				d2+=t2[i];
			}
			int ans=0;
			for(int i=1;i<=l;i++){
				string x="",xx="";
				for(int j=i;j<l;j++)x+=t1[j],xx+=t2[j];
				for(int j=r;j<=len;j++){
					string y="",yy="";
					for(int k=r+1;k<=j;k++)y+=t1[j],yy+=t2[j];
					string s1=x+d1+y,s2=xx+d2+yy;
					int L=1,R=len;
					while(L<R){
						int mid=L+R>>1;
						if(s[mid].x<s1)L=mid+1;
						else R=mid;
					}
					if(s[L].x==s1&&s[L].y==s2){
	//					cout<<i<<" "<<j<<"\len";
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		int pos1,pos2;
		for(int i=1;i<=len;i++){
			if(t1[i]=='b')pos1=i;
			if(t2[i]=='b')pos2=i;
		}
		int d=pos2-pos1;
		int L=1,R=n;
		while(L<R){
			int mid=L+R>>1;
			if(p[mid].sum<d)L=mid+1;
			else R=mid;
		}
		int ans=0;
		for(int i=L;i<=n&&p[i].sum==d;i++){
			if(pos1>fr[p[i].id]&&len-pos1>=bk[p[i].id])ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

