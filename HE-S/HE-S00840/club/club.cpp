#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int T,b[4];
int maxx(int a,int b,int c){
	int h=max(a,max(b,c));
	return h;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int n,eve,x,y,z,m,sum;
		cin>>n;eve=n/2;
		for(int i=1;i<=n;i++){	
			cin>>x>>y>>z;
			m=maxx(x,y,z);
			if(x==0&&z==0){
				if(y==1){
					b[1]++;
				}else if(y==2){
					b[2]++;
				}else if(y==3){
					b[3]++;
				}
			}
			if(m==x){
				b[1]++;
			}else if(m==y){
				b[2]++;
			}else{
				b[3]++;
			}
			if(maxx(b[1],b[2],b[3])<=eve){
				sum=sum+m;
			}			
		}
		cout<<sum<<'\n';
		sum=0;
		memset(b,0,sizeof(b));
	}
	return 0;
} 
