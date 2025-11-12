#include<bits/stdc++.h>
using namespace std;
long long fa[2100000];
long long minn[2100000];
long long biao[2100000];
long long flag=0;
struct node{
	long long last,next,val;
}a[2010000];
long long pi(long long x){
	if(x==fa[x])return x;
	return fa[x]=pi(fa[x]);
}
bool cmp(node a,node b){
	return a.val<b.val;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++)fa[i]=i;
	for(long long i=1;i<=m;i++){
		cin>>a[i].last>>a[i].next>>a[i].val;
	}
	if(k==0){
		long long cnt=0,ans=0;
		sort(a+1,a+1+m,cmp);
		for(long long i=1;i<=m;i++){
			long long n1=a[i].last;
			long long n2=a[i].next;
			if(pi(n1)!=pi(n2)){
				fa[pi(n1)]=fa[pi(n2)];
				cnt++;
				ans+=a[i].val;
			}
		}
		cout<<ans<<endl;
	}else{
		long long al=m;
	  for(long long i=1;i<=k;i++){
		  long long ci;
		  cin>>ci;
		  if(ci!=0)flag=1;
		  minn[i]=1e18;
		  for(long long j=1;j<=n;j++){
			  long long cost;
			  cin>>cost;
			  al++;
			  a[al].last=n+i;
			  a[al].next=j;
			  a[al].val=cost;
			  if(a[al].val<minn[i]){
				  minn[i]=a[al].val;
				  biao[i]=j;
			  }
		  }
		  minn[i]+=ci;
	   }
	   for(long long i=1;i<=n+k;i++)fa[i]=i;
	   if(flag==0){
		   long long cnt=0,ans=0;
		   sort(a+1,a+1+al,cmp);
		   for(long long i=1;i<=al;i++){
			  long long n1=a[i].last;
			  long long n2=a[i].next;
			  if(pi(n1)!=pi(n2)){
				fa[pi(n1)]=fa[pi(n2)];
				cnt++;
				ans+=a[i].val;
			  }
		   }
	   cout<<ans;
	  }else{
		   sort(a+1,a+1+al,cmp);
		  long long ans2=1e18;
		  for(int mask=0;mask<(1<<k);mask++){
			  for(long long i=1;i<=n+k;i++)fa[i]=i;
			  long long ans=0;
			  for(int j=0;j<k;j++){
				  if((mask&(1<<j))){
					  fa[pi(n+j+1)]=fa[pi(biao[j+1])];
					  ans=ans+minn[j+1];
					 // cout<<mask<<" "<<j+1<<" "<<minn[j+1]<<endl;
				  }
			  }
			  //cout<<ans<<endl;
			  for(long long i=1;i<=al;i++){
				  long long n1=a[i].last;
			      long long n2=a[i].next;
			      if(n1<=n||(mask&(1<<(n1-n-1)))){
					  if(pi(n1)!=pi(n2)){
				        fa[pi(n1)]=fa[pi(n2)];
				        ans+=a[i].val;
                       }
				  }
				  if(ans>ans2)break;
		    }
		    ans2=min(ans2,ans);
		    //cout<<mask<<" "<<ans<<endl;
	  }
	  cout<<ans2<<endl;
  }
}
   return 0;
}//100000
