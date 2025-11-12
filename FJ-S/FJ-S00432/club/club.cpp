#include<bits/stdc++.h>
#define int long long 
using namespace std;
int t,n,pos=0;
struct str{
	int num1,num2,num3;
	int add;
}s[112345];
vector<int> g[10];
struct node{
	int add;
	int w;  //Îó²î 
}a[112345];
bool cmp(node u,node v){
	return u.w<v.w;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=3;i++){
			while(g[i].size()){
				g[i].pop_back();
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&s[i].num1,&s[i].num2,&s[i].num3);
			if(s[i].num1>=s[i].num2 && s[i].num1>=s[i].num3){
				g[1].push_back(i);
				ans+=s[i].num1;
			}
			else if(s[i].num2>=s[i].num1 && s[i].num2>=s[i].num3){
				g[2].push_back(i);
				ans+=s[i].num2;
			}
			else{
				g[3].push_back(i);
				ans+=s[i].num3;
			}
		}
		pos=0;
		if(g[1].size()>n/2){
			for(int i=0;i<g[1].size();i++){
				a[++pos].add=g[1][i];
				a[pos].w=s[a[pos].add].num1-s[a[pos].add].num2;
				a[pos].w=min(s[a[pos].add].num1-s[a[pos].add].num3,a[pos].w);
			}
			sort(a+1,a+g[1].size()+1,cmp);
			int need=g[1].size()-n/2;
			for(int i=1;i<=need;i++){
				ans-=a[i].w;
			}
			printf("%lld\n",ans);
		}
		else if(g[2].size()>n/2){
			for(int i=0;i<g[2].size();i++){
				a[++pos].add=g[2][i];
				a[pos].w=s[a[pos].add].num2-s[a[pos].add].num1;
				a[pos].w=min(s[a[pos].add].num2-s[a[pos].add].num3,a[pos].w);
			}
			sort(a+1,a+g[2].size()+1,cmp);
			int need=g[2].size()-n/2;
			//cout<<g[2].size()<<endl;
			for(int i=1;i<=need;i++){
				//cout<<a[i].add<<" ";
				ans-=a[i].w;
			}
			//cout<<endl;
			printf("%lld\n",ans);
		}
		else if(g[3].size()>n/2){
			for(int i=0;i<g[3].size();i++){
				a[++pos].add=g[3][i];
				a[pos].w=s[a[pos].add].num3-s[a[pos].add].num1;
				a[pos].w=min(s[a[pos].add].num3-s[a[pos].add].num2,a[pos].w);
			}
			sort(a+1,a+g[3].size()+1,cmp);
			int need=g[3].size()-n/2;
			for(int i=1;i<=need;i++){
				ans-=a[i].w;
			}
			printf("%lld\n",ans);
		}
		else  printf("%lld\n",ans);
	}
	return 0;
} 
