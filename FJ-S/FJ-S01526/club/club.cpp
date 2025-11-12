#include<bits/stdc++.h>
using namespace std;

long long t,n,suma,sumb,sumc,sum,maxsum;
long long sumab,sumac,sumbc,sumabc;
long long ta[114514],tb[114514],tc[114514];
int xs[100005][4];

void dfs(int k){
	if(k>n){
		maxsum=max(sum,maxsum);
		return ;
	}
	if(suma+1<=n/2){
		sum+=xs[k][1];
		suma++;
		dfs(k+1);
		suma--;
		sum-=xs[k][1];
	}
	if(sumb+1<=n/2){
		sum+=xs[k][2];
		sumb++;
		dfs(k+1);
		sumb--;
		sum-=xs[k][2];
	}
	if(sumc+1<=n/2){
		sum+=xs[k][3];
		sumc++;
		dfs(k+1);
		sumc--;
		sum-=xs[k][3];
	}
}

int main(){
	/*
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	*/
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		maxsum=-1;
		sum=0;
		suma=0;
		sumb=0;
		sumc=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>xs[i][1]>>xs[i][2]>>xs[i][3];
			ta[i]=xs[i][1];
			tb[i]=xs[i][2];
			tc[i]=xs[i][3];
			if(xs[i][1]==0)
				suma++;
			if(xs[i][2]==0)
				sumb++;
			if(xs[i][3]==0)
				sumc++;
		}
		if(sumc==n){
			if(sumb==n){
				if(suma==n){
					cout<<0<<endl;
					continue;
				}
				sort(ta+1,ta+n+1);
				for(int i=n;i>n/2;i--)
					sum+=ta[i];
				cout<<sum<<endl;
				continue;
			}
			else{
				if(suma==n){
					sort(tb+1,tb+n+1);
					for(int i=n;i>n/2;i--)
						sum+=tb[i];
					cout<<sum<<endl;
					continue;
				}
				
			}
		}
		else{
			if(suma==n){
				if(sumb==n){
					sort(tc+1,tc+n+1);
					for(int i=n;i>n/2;i--)
						sum+=tc[i];
					cout<<sum<<endl;
					continue;
				}
				else{
					
				}
			}
			else{
				if(sumb==n){
					
				}
			}
		}
		dfs(1);
		cout<<maxsum<<endl;
	}
	return 0;
}

/*
			
*/
