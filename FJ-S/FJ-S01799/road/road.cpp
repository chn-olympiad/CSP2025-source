#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int map_[10001][10001];
int new_[11][100001],head;
bool map1_[10001],new1_[11],key[11];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
		memset(map_,1000000001,sizeof map_);
		memset(map1_,false,sizeof map1_);
		cin>>n>>m>>k;
		for(int i=1;i<=m;++i){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);//cout<<a<<" "<<b<<endl;
			if(a>n||b>n)continue;
			map_[a][b]=min(map_[a][b],c);
			map_[b][a]=map_[a][b];
		}
		//cout<<1145;
		for(int i=1;i<=k;++i){
			//cout<<i<<" i"<<endl;
			cin>>new_[i][0];
			if(new_[i][0]==0){
				new1_[i]=true;
				//cout<<1;
			}
			for(int j=1;j<=n;++j){
				int l;
				cin>>l;
			//	cout<<l<<" "<<"l"<<" "<<j<<" "<<n<<endl;
				new_[i][j]=l;
				if(l==0){
				key[i]=true;	
				}
			}
				if(new1_[i]&&key[i]){
					for(int j=1;j<=n;++j){
						if(new_[i][j]==0){
							head=j;
							for(int kl=1;kl<=n;++kl){
								if(kl==j)continue;
								map_[j][kl]=min(map_[j][kl],new_[i][kl]);
								map_[kl][j]=map_[j][kl];
							}
						}
					}
				}
		}
		if(k==0){
			long long s=0;
			map1_[1]=true;
			long long minn=100000001;
			int mi=1;
			for(int i=1;i<=n;++i){
				for(int j=2;j<=n;++j){
					if(map1_[j]==true)continue;
					if(map_[1][j]<minn){
						mi=j;
						minn=map_[1][j];
				}
			}
			s+=minn;
			map1_[mi]==true;
			for(int i=2;i<=n;++i){
				if(map1_[i]!=true){
					map_[1][i]=min(map_[1][i],map_[mi][i]);
				}
				else{
					map_[1][i]=1000000001;
				}
			}
		}
			cout<<s<<endl;	
		}
		cout<<new1_[1];
		if(key[1]==true&&new1_[1]==true){
			long long s=0;
			map1_[head]=true;
			long long minn=100000001;
			int mi=head;
			for(int i=1;i<=n;++i){
				for(int j=2;j<=n;++j){
					if(map1_[j]==true)continue;
					if(map_[head][j]<minn){
						mi=j;
						minn=map_[head][j];
				}
			}
			s+=minn;
			map1_[mi]==true;
			for(int i=2;i<=n;++i){
				if(map1_[i]!=true){
					map_[1][i]=min(map_[1][i],map_[mi][i]);
				}
				else{
					map_[1][i]=1000000001;
				}
			}
		}
			cout<<s<<endl;
		}
	return 0;
}
