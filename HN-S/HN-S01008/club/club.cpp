#include<bits/stdc++.h>
using namespace std;
int n,t,cnt,s[4];
struct Node{
	int a,la,b,lb,c,lc;
}d[100005];
bool cmp(Node a,Node b){
	if(a.a==b.a){
		if(a.b==b.b){
			return a.c<=b.c;
		}
		return a.b<=b.b;
	}
	return a.a<=b.a;
}
int dfs(int n,int j,int sum,int o[4],int num){
	if(j==0)return sum;
	if(o[d[j].la]<n/2){
		o[d[j].la]++;
		num=max(num,dfs(n,j-1,sum+d[j].a,o,num));
		o[d[j].la]--;
		o[d[j].lb]++;
		num=max(num,dfs(n,j-1,sum+d[j].b,o,num));
		o[d[j].lb]--;
		o[d[j].lc]++;
		num=max(num,dfs(n,j-1,sum+d[j].c,o,num));
		o[d[j].lc]--;
	}
	else if(o[d[j].lb]<n/2){
		o[d[j].lb]++;
		num=max(num,dfs(n,j-1,sum+d[j].b,o,num));
		o[d[j].lb]--;
		o[d[j].lc]++;
		num=max(num,dfs(n,j-1,sum+d[j].c,o,num));
		o[d[j].lc]--;
	}
	else if(o[d[j].lc]<n/2){
		o[d[j].lc]++;
		num=max(num,dfs(n,j-1,sum+d[j].c,o,num));
		o[d[j].lc]--;
	}
	return num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		cnt=0;
		s[1]=0,s[2]=0,s[3]=0;
		for(int j=1;j<=n;j++){
			int a,b,c;
			cin>>a>>b>>c;
			if(a>=b&&a>=c){
				d[j].a=a,d[j].la=1;
				if(b>=c){
					d[j].b=b,d[j].lb=2;
					d[j].c=c,d[j].lc=3;
				}
				if(b<c){
					d[j].b=c,d[j].lb=3;
					d[j].c=b,d[j].lc=2;
				}
			}
			if(b>=a&&b>=c){
				d[j].a=b,d[j].la=2;
				if(a>=c){
					d[j].b=a,d[j].lb=1;
					d[j].c=c,d[j].lc=3;
				}
				if(a<c){
					d[j].b=c,d[j].lb=3;
					d[j].c=a,d[j].lc=1;
				}
			}
			if(c>=a&&c>=b){
				d[j].a=c,d[j].la=3;
				if(a>=b){
					d[j].b=a,d[j].lb=1;
					d[j].c=b,d[j].lc=2;
				}
				if(a<b){
					d[j].b=b,d[j].lb=2;
					d[j].c=a,d[j].lc=1;
				}
			}
		}
		sort(d+1,d+n+1,cmp);
		s[1]=1;
		int x=dfs(n,n,d[n].a,s,0);
		s[1]=0;
		s[2]=1;
		int y=dfs(n,n,d[n].b,s,0);
		s[2]=0;
		s[3]=1;
		int z=dfs(n,n,d[n].c,s,0);
		s[3]=0;  
		cnt=max(max(x,y),z);
		cout<<cnt<<endl;
	}
	return 0;
}
