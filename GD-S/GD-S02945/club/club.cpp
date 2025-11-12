#include<bits/stdc++.h>
#define ll long long int
#define inc(i,l,r) for(ll i=l;i<=r;++i)
using namespace std;
ll t,n,con,sum=0,ans=0;
ll v[100050];
struct mate{
	ll a,b,c;
	ll max1,p1,max2;
	ll cha;	
}tx[100050];
void dfs(ll x,ll suma,ll sumb,ll sumc){
	if(x==n+1){
		ans=max(ans,sum);
		return;
	}
	if(suma<con){
	sum+=tx[x].a;
	dfs(x+1,suma+1,sumb,sumc);
	sum-=tx[x].a;
	}
	if(sumb<con){
	sum+=tx[x].b;
	dfs(x+1,suma,sumb+1,sumc);
	sum-=tx[x].b;
	}
	if(sumc<con){
	sum+=tx[x].c;
	dfs(x+1,suma,sumb,sumc+1);
	sum-=tx[x].c;
	}
}
bool cmp(mate a,mate b){
	return a.cha<b.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;		
	while(t--){		
		cin>>n;
		ll con=n/2,cnta=0,cntb=0,cntc=0;
		inc(i,1,n){			
		cin>>tx[i].a>>tx[i].b>>tx[i].c;
		ll a=tx[i].a,b=tx[i].b,c=tx[i].c;
		if(a>=b&&b>=c){
			tx[i].max1=a;tx[i].max2=b;
			tx[i].p1=1;
		}
		else if(a>=c&&c>=b){
			tx[i].max1=a;tx[i].max2=c;
			tx[i].p1=1;
		}	
		else if(b>=c&&c>=a){
			tx[i].max1=b;tx[i].max2=c;
			tx[i].p1=2;
		}
		else if(b>=a&&a>=c){
			tx[i].max1=b;tx[i].max2=a;
			tx[i].p1=2;
		}
		else if(c>=a&&a>=b){
			tx[i].max1=c;tx[i].max2=a;
			tx[i].p1=3;
		}
		else{
			tx[i].max1=c;tx[i].max2=b;
			tx[i].p1=3;
		}
		tx[i].cha=tx[i].max1-tx[i].max2;
		}
		inc(i,1,n){
			sum+=tx[i].max1;
			v[i]=tx[i].p1;
			if(tx[i].p1==1)cnta++;
			else if(tx[i].p1==2)cntb++;
			else cntc++;
		}
				
		if(cnta>con){
			ll cc=cnta-con;
			inc(i,1,n)if(v[i]!=1)tx[i].cha=99999;
			sort(tx,tx+n+1,cmp);
			//inc(i,1,n)cout<<tx[i].cha<<" ";
	        inc(i,1,cc)sum-=tx[i].cha;
		}
		if(cntb>con){
			ll cc=cntb-con;
			inc(i,1,n)if(v[i]!=2)tx[i].cha=99999;
			sort(tx,tx+n+1,cmp);
			//inc(i,1,n)cout<<tx[i].cha<<" ";
	        inc(i,1,cc)sum-=tx[i].cha;
		}
		if(cntc>con){
			ll cc=cntc-con;
			inc(i,1,n)if(v[i]!=3)tx[i].cha=99999;
			sort(tx,tx+n+1,cmp);
			//inc(i,1,n)cout<<tx[i].cha<<" ";
	        inc(i,1,cc)sum-=tx[i].cha;
		}
		//dfs(1,0,0,0);	
		cout<<sum<<endl;
		//ans=0;
		sum=0;		
	}
	return 0;
	
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
