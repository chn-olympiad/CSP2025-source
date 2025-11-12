#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct _{
	int a,b,c;
	int cha;
}s[N];
int aa[N],bb[N],cc[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,sum=0;
		cin>>n;
		int ai=0,bi=0,ci=0;
		for(int i=0;i<n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			int a=s[i].a,b=s[i].b,c=s[i].c;
			int maxn=max(a,max(b,c)),minn=min(a,min(b,c));
			s[i].cha=2*maxn-a-b-c+minn;
			if(a>b && a>c)sum+=a,aa[ai++]=s[i].cha;
			if(b>a && b>c)sum+=b,bb[bi++]=s[i].cha;
			if(c>a && c>b)sum+=c,cc[ci++]=s[i].cha;
		}
		if(ai>n/2){
			sort(aa,aa+ai);
			int i=0;
			while(ai>n/2){
				sum-=aa[i++];
				ai--;
			}
		}
		if(bi>n/2){
			sort(bb,bb+bi);
			int i=0;
			while(bi>n/2){
				sum-=bb[i++];
				bi--;
			}
		}
		if(ci>n/2){
			sort(cc,cc+ci);
			int i=0;
			while(ci>n/2){
				sum-=cc[i++];
				ci--;
			}
		}
		cout<<sum<<endl;
	} 
} 
