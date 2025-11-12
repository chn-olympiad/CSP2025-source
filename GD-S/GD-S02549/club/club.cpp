#include <bits/stdc++.h>
using namespace std;
long long t,i,j,v,ans,k,n;
struct node{
	long long a,b,c,cha;	
}s[200005];
vector<node> x[5];
bool cmp(node a,node b){
	return a.cha<b.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(v=1;v<=t;v++){
		cin>>n;
		for(i=1;i<=n;i++){

			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].a>=s[i].b&&s[i].a>=s[i].c){
				ans+=s[i].a;
				s[i].cha=s[i].a-max(s[i].b,s[i].c);
				x[1].push_back(s[i]);
			}
			else if(s[i].b>=s[i].c&&s[i].b>=s[i].a){
				ans+=s[i].b;
			
				s[i].cha=s[i].b-max(s[i].a,s[i].c);
				x[2].push_back(s[i]);
			}
			else{
				ans+=s[i].c;
		
				s[i].cha=s[i].c-max(s[i].b,s[i].a);
				x[3].push_back(s[i]);
			}
			
			
		}
		for(i=1;i<=3;i++){
			if(x[i].size()>n/2){
				sort(x[i].begin(),x[i].end(),cmp);
				for(j=0;j<x[i].size()-n/2;j++){
					ans-=x[i][j].cha;
				}
				break;
			}
		}
		cout<<ans<<endl;
		ans=0;
		for(i=1;i<=3;i++) x[i].clear();
	}
	return 0;
} 
