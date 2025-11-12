#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int zu[10],zua[N],zub[N],zuc[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(zu,0,sizeof(zu));
		int n;
		cin>>n;
		long long sum=0;
		int ka=0,kb=0,kc=0;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			int mx=max(a,max(b,c));
			sum+=mx;
			if(mx==a){
				zua[++ka]=mx-max(b,c);
				zu[1]++;
			}
			else if(mx==b){
				zub[++kb]=mx-max(a,c);
				zu[2]++;
			}
			else{
				zuc[++kc]=mx-max(b,a);
				zu[3]++;
			}	
		}
		if(zu[1]>n/2){
			sort(zua+1,zua+ka+1);
			int ii=1;
			while(zu[1]>n/2){
				sum-=zua[ii];
				ii++;
				zu[1]--;
			}
		}
		else if(zu[2]>n/2){
			sort(zub+1,zub+kb+1);
			int iii=1;
			while(zu[2]>n/2){
				sum-=zub[iii];
				iii++;
				zu[2]--;
			}
		}
		else if(zu[3]>n/2){
			sort(zuc+1,zuc+kc+1);
			int iiii=1;
			while(zu[3]>n/2){
				sum-=zuc[iiii];
				iiii++;
				zu[3]--;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
