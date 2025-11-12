#include<bits/stdc++.h>
using namespace std;
long long club[300001],club2[300001],ttt[6];
long long son1=0,son2=0,son3=0,ans=0,maxx=0,n,m;
void dfs(long long a,long long b){
	if(a>n){
		if(ans>=maxx){
			maxx=ans;
		}
		return ;
	}
	if(club2[3*a-2]==0){
		if(son1<n/2){
			club2[3*a-2]=1;
			ans+=club[3*a-2];
		    son1++;
		    dfs(a+1,maxx);
		    son1--;
		    club2[3*a-2]=0;
		    ans-=club[3*a-2];
		}
    }
	if(club2[3*a-1]==0){
		if(son2<n/2){
			club2[3*a-1]=1;
			ans+=club[3*a-1];
			son2++;
			dfs(a+1,maxx);
			son2--;
			club2[3*a-1]=0;
			ans-=club[3*a-1];
		}
	}
    if(club2[3*a]==0){
		if(son3<n/2){
			club2[3*a]=1;
			ans+=club[3*a];
			son3++;
			dfs(a+1,maxx);
			son3--;
			club2[3*a]=0;
			ans-=club[3*a];
		}
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	for(int i=1;i<=t;i++){
		maxx=0;
		cin>>n;
		for(int j=1;j<=3*n;j++){
			cin>>club[j];
		}
		dfs(1,maxx);
		ttt[i]=maxx;
	}
	for(int i=1;i<=t;i++){
		cout<<ttt[i]<<endl;
	}
	return 0;
}
