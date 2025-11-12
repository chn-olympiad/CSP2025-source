#include<bits/stdc++.h> 
using namespace std;
int t,n,numx[4],ans;
struct node{
	int a,b,c;
}a[200005];
struct che{
	int x,num;
};
bool cmd1(node a,node b){
	int s1=a.a+a.b+a.c;
	int s2=b.a+b.b+b.c;
	return s1>s2;
}
bool cmd2(che a,che b){
	if(a.x!=b.x)return a.x>b.x;
	else return numx[a.num]<numx[b.num];
}
int check(int n,int a,int b,int c){
	che s[3];
	s[0].x=a,s[0].num=1,s[1].x=b,s[1].num=2,s[2].x=c,s[2].num=3;
	sort(s,s+3,cmd2);
    if(n==1)return s[0].num;
    else if(n==2)return s[1].num;
    else return s[2].num;
}
int sum(int n,int a,int b,int c){
	if(n==1)return a;
	if(n==2)return b;
	else return c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		memset(numx,0,sizeof(numx));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(j==1)cin>>a[i].a;
				else if(j==2)cin>>a[i].b;
				else cin>>a[i].c;
			}
		}
		sort(a+1,a+n+1,cmd1);
		for(int i=1;i<=n;i++){
			int s1=check(1,a[i].a,a[i].b,a[i].c);
            int s2=check(2,a[i].a,a[i].b,a[i].c);
            int s3=check(3,a[i].a,a[i].b,a[i].c);
            if(numx[s1]+1<=n/2){
            	numx[s1]++;
            	ans+=sum(s1,a[i].a,a[i].b,a[i].c);
			}
			else if(numx[s2]+1<=n/2){
				numx[s2]++;
				ans+=sum(s2,a[i].a,a[i].b,a[i].c);
			}
			else{
				numx[s3]++;
				ans+=sum(s3,a[i].a,a[i].b,a[i].c);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
