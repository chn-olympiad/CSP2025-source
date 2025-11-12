#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std; 
int n;
struct Student{
	int a,b,c,s;
}stu[100100];
int maxn=0;
void dfs(int k,int A,int B,int C,int s){
	if(k>n){
		maxn=max(maxn,s);
		return;
	}
	if(A+1<=n/2){
		dfs(k+1,A+1,B,C,s+stu[k].a); 
	}
	if(B+1<=n/2){
		dfs(k+1,A,B+1,C,s+stu[k].b); 
	}
	if(C+1<=n/2){
		dfs(k+1,A,B,C+1,s+stu[k].c); 
	}
}
bool cmp(Student x,Student y){
	return x.a>y.a;
}
bool cmp2(Student x,Student y){
	return x.s>y.s;
}
void solve(){
	cin>>n;
	int f=1,ff=1;
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		stu[i]={x,y,z,y-z};
		if(y==0){
			f=0;
		}
		if(z==0){
			ff=0;
		}
	}
	if(n<=30){
		dfs(1,0,0,0,0);
		cout<<maxn;
		return;
	}else if(f && ff){
		sort(stu+1,stu+n+1,cmp);
		int s=0;
		for(int i=1;i<=n/2;i++){
			s+=stu[i].a;
		}
		cout<<s;
		return;
	}else if(ff){
		sort(stu+1,stu+n+1,cmp2);
		int s=0;
		for(int i=1;i<=n/2;i++){
			s+=stu[i].a;
		}
		for(int i=n/2+1;i<=n;i++){
			s+=stu[i].b;
		}
		cout<<s;
		return;
	}else{
		dfs(1,0,0,0,0);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
