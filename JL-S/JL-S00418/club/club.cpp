#include<bits/stdc++.h>
using namespace std;
int fmax(int a,int b,int c){
	if(a>=b&&a>=c)return a;
	if(b>=a&&b>=c)return b;
	return c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t,n;
	
	cin>>t;
	
	for(int i=0;i<t;i++){
		
		cin>>n;
		int team[n][3],cl[3]={},ch[3]={},al[n]={},pmaxnum[n]={},tmaxnum=0,tmaxid=0,tmyd=0,cnt=0;
		for(int j=0;j<n;j++){
			for(int k=0;k<3;k++) cin>>team[j][k];
			pmaxnum[j]=fmax(team[j][0],team[j][1],team[j][2]);
		}
		
		while(1){
			tmaxid=0;
			tmaxnum=0;
			if(cl[0]>=n/2) ch[0]=1;
			if(cl[1]>=n/2) ch[1]=1;
			if(cl[1]>=n/2) ch[2]=1;
			
			if(cnt==n){
				cnt=0;
				break;
			}
			
			for(int j=0;j<n;j++){
				if(tmaxnum<pmaxnum[j]&&al[j]==0){
					tmaxnum=pmaxnum[j];
					tmaxid=j;
				}
			}
			
			al[tmaxid]+=1;
			cnt+=1;
			if(team[tmaxid][0]==tmaxnum&&ch[0]==0) cl[0]+=1;
			if(team[tmaxid][1]==tmaxnum&&ch[1]==0) cl[1]+=1;
			if(team[tmaxid][2]==tmaxnum&&ch[2]==0) cl[2]+=1;

			tmyd+=tmaxnum;
			
		}
		
		cout<<tmyd<<endl;
		
	}
	return 0;
}
