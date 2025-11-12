#include<bits/stdc++.h>
using namespace std;
const int N=100010;
struct nodee{
	int p;
	char q;
}cha;
struct node{
	int a,b,c;
	nodee cha;
}s[N];
bool cmp(node x,node y){
	return x.cha.p>=y.cha.p;
}
int T,ans=0,ai=0,bi=0,ci=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0,ai=0,bi=0,ci=0;
		int n; 
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].a>=s[i].b&&s[i].a>=s[i].c){
				s[i].cha.p=2*s[i].a-s[i].b-s[i].c;
				s[i].cha.q='a';
			}else if(s[i].b>=s[i].a&&s[i].b>=s[i].c){
				s[i].cha.p=2*s[i].b-s[i].a-s[i].c;	
				s[i].cha.q='b';
			}else if(s[i].c>=s[i].b&&s[i].c>=s[i].a){
				s[i].cha.p=2*s[i].c-s[i].a-s[i].b;	
				s[i].cha.q='c';
			}
			//差的最大值 
			//cout<<s[i].cha.p;//测试 
		}	
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(ai<=n/2&&s[i].cha.q=='a'){
				ans+=s[i].a;
				ai++;
			}else if(bi<=n/2&&s[i].cha.q=='b'){
				ans+=s[i].b;
				bi++;
			}else if(ci<=n/2&&s[i].cha.q=='c'){
				ans+=s[i].c;
				ci++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

