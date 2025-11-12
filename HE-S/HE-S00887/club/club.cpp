#include<bits/stdc++.h>

using namespace std;
int n,t;
int p[100010];
int b[4];
int w[100010][4];
struct pp{
	int x,id,j;
}a[1000000];
bool cmp(pp a,pp b){
	return a.x>b.x;
}
long long ma=-1,s2=0,id;
int dfs(int id){
	if(id>n){
	ma=max(s2,ma);
	}
	else {
		for(int i=1;i<=3;i++){
	   if(b[i]<n/2) 
	   { s2+=w[id][i];b[i]++;
	   	dfs(id+1);
	   	b[i]--;s2-=w[id][i];
	   }
	   else continue; 	
	}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{    long long s=0; int sum=0;
		cin>>n;
		if(n<=14){
		ma=-1,s2=0;
			for(int i=1;i<=n;i++) cin>>w[i][1]>>w[i][2]>>w[i][3];
			dfs(1);
			cout<<ma<<endl;
		}
		else{
			b[1]=b[2]=b[3]=0;
		int cnt=0;
	   for(int i=1;i<=n;i++)
	   {
	   	 cin>>a[++cnt].x; a[cnt].id=i;a[cnt].j=1;
	   	 cin>>a[++cnt].x;a[cnt].id=i;a[cnt].j=2;
	   	 cin>>a[++cnt].x;a[cnt].id=i;a[cnt].j=3;
	   }
	   sort(a+1,a+1+cnt,cmp);
	    for(int i=1;i<=cnt;i++)
	    {
	   	        if(!p[a[i].id]&&b[a[i].j]<(n/2))
	   	        {    
	   	         s+=a[i].x;	b[a[i].j]++;sum++;p[a[i].id]=1;
				}
		 if(sum==n) break;		
		}
		cout<<s<<endl;	
		for(int i=1;i<=n;i++) p[i]=0;
		}
	}
	return 0;
}
