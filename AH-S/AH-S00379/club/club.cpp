#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
	int ma(){
		return max(a,max(b,c));
	}
}s[100010];
int n;
bool cmp(node a,node b){
	return a.ma()>b.ma();
}
int ans=0;
void dfs(int x,int h,int a,int b,int c){
	ans=max(h,ans);
	if(a<n/2)dfs(x+1,h+s[x].a,a+1,b,c);
	if(b<n/2)dfs(x+1,h+s[x].b,a,b+1,c);
	if(c<n/2)dfs(x+1,h+s[x].c,a,b,c+1);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		long long hh=0;
		bool flag1=1;
		for(int i=0;i<n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			hh+=s[i].ma();
			if(s[i].b||s[i].c)flag1=0;
		}
		if(flag1){
			long long h=0;
			sort(s,s+n,cmp);
			for(int i=0;i<n;i++)h+=s[i].a;
			cout<<h<<endl;
		}else if(n<=17){
			dfs(0,0,0,0,0);
			cout<<ans<<endl;
		}else{
			cout<<hh<<endl;
		}
	}
	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
	vector<pair<int,int>>ma(){
		vector<pair<int,int>>s(3);
		s[0]=make_pair(a,0);
		s[1]=make_pair(b,1);
		s[2]=make_pair(c,2);
		sort(s.begin(),s.end());
		return s;
	}
}a[100010];
bool cmp(node a,node b){
	if(a.ma()[2].first!=b.ma()[2].first)return a.ma()[2].first>b.ma()[2].first;
	if(a.ma()[1].first!=b.ma()[1].first)return a.ma()[1].first>b.ma()[1].first;
	return a.ma()[0].first>b.ma()[0].first;
}
int h;
int main(){
	freopen("club1.in","r",stdin);
	freopen("club1.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int c[3]={0,0,0};
		h=0;
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		sort(a,a+n,cmp);
		
		for(int i=0;i<n;i++){
			if(c[a[i].ma()[2].second]<n/2){
				c[a[i].ma()[2].second]++;
				h+=a[i].ma()[2].first;
			}else if(c[a[i].ma()[1].second]<n/2){
				c[a[i].ma()[1].second]++;
				h+=a[i].ma()[1].first;
			}else if(c[a[i].ma()[0].second]<n/2){
				c[a[i].ma()[0].second]++;
				h+=a[i].ma()[0].first;
			}
		}
		cout<<h<<endl;
	}
	return 0;
}
*/
