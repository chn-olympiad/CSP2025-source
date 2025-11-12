#include<bits/stdc++.h>
using namespace std;
struct stu{
	int a,b,c;
}arr[int(1e5+10)];
long long n,ans=0;
map<pair<int,long long>,bool> ma;
map<pair<int,long long>,bool> maa;
void dfs(int x,long long cnt,int a,int b,int c){
	if(ma[{x,cnt}]){
		//cout<<'a';
		return;
	}
	ma[{x,cnt}]=1;
	if(x>n){
		ans=max(cnt,ans);
		return;
	}
//int maxx=max({arr[x].a,arr[x].b,arr[x].c}),ymaxx=min({a,b,c});
		if(a<n/2)dfs(x+1,cnt+arr[x].a,a+1,b,c);
		if(b<n/2)dfs(x+1,cnt+arr[x].b,a,b+1,c);
		if(c<n/2)dfs(x+1,cnt+arr[x].c,a,b,c+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ma=maa;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>arr[i].a>>arr[i].b>>arr[i].c;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
//Ren5Jie4Di4Ling5%*/
//#include<bits/stdc++.h>
//using namespace std;
//struct stu{
//	int a,b,c,ma;
//	bool t;
//}arr[int(1e5+10)];
//bool cmp1(stu a,stu b,stu c){return a.a>b.a;}
//bool cmp2(stu a,stu b,stu c){return a.b>b.b;}
//bool cmp3(stu a,stu b,stu c){return a.c>b.c;}
//long long n,ans=0;
//int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
//	int t;
//	cin>>t;
//	while(t--){
//
//		ans=0;
//		cin>>n;
//		int xa=0,xb=0,xc=0;
//		for(int i=1;i<=n;i++){
//			cin>>arr[i].a>>arr[i].b>>arr[i].c;
//			if(arr[i].a>=arr[i].b && arr[i].a>=arr[i].c) ma=1;
//			if(arr[i].b>=arr[i].a && arr[i].b>=arr[i].c) ma=2;
//			if(arr[i].c>=arr[i].a && arr[i].c>=arr[i].b) ma=3;
//			if(arr[i].a==arr[i].b && arr[i].a==arr[i].c) ma=4;
//			arr[i].t=0; 
//		}
//		
//		cout<<ans<<'\n';
//	}
//	return 0;
//}
////Ren5Jie4Di4Ling5%
