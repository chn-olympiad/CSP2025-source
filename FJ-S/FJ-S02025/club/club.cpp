#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
int n,t;
struct node{int a,b,c,x,tp;}s[N];
bool cmp(node s1,node s2){
	return s1.x<s2.x;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0,n1=0,n2=0,n3=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>s[i].a>>s[i].b>>s[i].c;
		for(int i=1;i<=n;i++){
			if(s[i].a>=s[i].b&&s[i].a>=s[i].c){
				n1++,ans+=s[i].a;s[i].tp=1;
			}
			else if(s[i].b>=s[i].c){
				n2++,ans+=s[i].b;s[i].tp=2;
			}
			else{
				n3++,ans+=s[i].c;s[i].tp=3;
			}
		}
		if(n1>n/2){
			for(int i=1;i<=n;i++){
				if(s[i].tp!=1){
					s[i].x=N;
					continue;
				}
				s[i].x=s[i].a-max(s[i].b,s[i].c);
			}
			sort(s+1,s+n+1,cmp);
			for(int i=1;i<=(n1-n/2);i++)ans-=s[i].x;
		}
		else if(n2>n/2){
			for(int i=1;i<=n;i++){
				if(s[i].tp!=2){
					s[i].x=N;
					continue;
				}
				s[i].x=s[i].b-max(s[i].a,s[i].c);
			}
			sort(s+1,s+n+1,cmp);
			for(int i=1;i<=(n2-n/2);i++)ans-=s[i].x;
		}
		else if(n3>n/2){
			for(int i=1;i<=n;i++){
				if(s[i].tp!=3){
					s[i].x=N;
					continue;
				}
				s[i].x=s[i].c-max(s[i].b,s[i].a);
			}
			sort(s+1,s+n+1,cmp);
			for(int i=1;i<=(n3-n/2);i++)ans-=s[i].x;
		}
		cout<<ans<<endl;
	}
	return 0;
}