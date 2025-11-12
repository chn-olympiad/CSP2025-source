#include<bits/stdc++.h>
using namespace std;
long long q[10010][4],t,n,sum,a,b,c,sa,sb,sc;
long long mk[10010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		sa=sb=sc=0;
		for(int i=1;i<=10010;++i)mk[i]=0;
		for(int i=1;i<=n;++i){
			cin>>a>>b>>c;
			long long tmp=max(max(a,b),c);
			sum+=tmp;
			if(tmp==a)sa++;
			else if(tmp==b)sb++;
			else sc++;
			a-=tmp;b-=tmp;c-=tmp;
			q[i][1]=-a;q[i][2]=-b;q[i][3]=-c;
		}
		int flag=0;
		int tmp=max(max(sa,sb),sc);
		if(sa==tmp)flag=1;
		else if(sb==tmp)flag=2;
		else flag=3;
		for(int i=1;i<=n;++i){
			if(q[i][flag]==0){
				int minn=20001;
				for(int j=1;j<=3;++j){
					if(q[i][j]<minn&&q[i][j]!=0)minn=q[i][j];
				}
				mk[i]=minn;
			}
		}
		int h=0;
		sort(mk+1,mk+n+1);
		while(tmp>(n/2)){
			h++;
			if(mk[h]==0)continue;
			else{
				sum-=mk[h];
				tmp--;
			} 
			
		}
		cout<<sum<<endl;
	}
	return 0;
} 

