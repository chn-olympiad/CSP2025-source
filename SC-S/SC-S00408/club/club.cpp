#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+5;
struct node{
	int num;//满意度 
	int group;//部门 
	int id;//第几个人 
}s[N];
bool vis[N];//是否有部门 
bool cmp(node a,node b){
	return a.num > b.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t; cin>>t;
	while(t--){
		int n,satis=0,t=1; 
		cin>>n;
		int a1n=n/2,a2n=n/2,a3n=n/2;//人数 
		for(int i=1;i<=n;i++){
			int a1,a2,a3;
			cin>>a1; 
			s[t].num=a1; s[t].group=1; s[t].id=i; t++;
			cin>>a2; 
			s[t].num=a2; s[t].group=2; s[t].id=i; t++;
			cin>>a3; 
			s[t].num=a3; s[t].group=3; s[t].id=i; t++;
		}
		sort(s+1,s+3*n+1,cmp);
		int cnt=0;
		for(int i=1;i<=3*n;i++){
			if(s[i].group==1 && a1n>0 && !vis[s[i].id]){
				satis+=s[i].num;//求满意度
				a1n--; cnt++; 
				vis[s[i].id]=true;
			}else if(s[i].group==2 && a2n>0 && !vis[s[i].id]){
				satis+=s[i].num;//求满意度 
				a2n--; cnt++; 
				vis[s[i].id]=true;
			}else if(s[i].group==3 && a3n>0 && !vis[s[i].id]){
				satis+=s[i].num;//求满意度 
				a3n--; cnt++; 
				vis[s[i].id]=true;
			}
			if(cnt==n) break;
		}
		cout<<satis<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 