#include<fstream>
using namespace std;
ifstream cin("road.in");
ofstream cout("road.out");
int r[10011][10011];
int kk[11]={};
int kb[11]={};
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		for(int j=1;j<=n+k;j++){
			r[i][j]=1000000001;
		}
	}
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		r[a][b]=c;
		r[b][a]=c;
	}
	for(int i=1;i<=k;i++){
		cin>>kk[i];
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
			r[n+i][j]=a;
			r[j][n+i]=a;
		}
	}
	long long dis[10011]={};
	for(int i=1;i<=n;i++){
		dis[i]=r[1][i];
	}
	for(int i=n+1;i<=n+k;i++){
		dis[i]=r[1][i]+kk[i-n];
	}
	//
	int count=0;
	int book[10011]={};
	for(int i=1;i<=n+k;i++){
		count++;
		int mr=1000000001;
		int L=0;
		for(int j=n+k;j>=1;j--){
			if(book[j]==0&&dis[j]<mr){
				mr=dis[j];
				L=j;
			}
		}
		book[L]=1;
		if(L>n&&kb[L-n]==0){
			kk[L-n]=0;
			kb[L-n]=1;
			count--;

		for(int j=n+k;j>=2;j--){
			if(j<=n){
				if(dis[j]>r[L][j]){
					dis[j]=r[L][j];
				}
			}
			else{
				if(dis[j]>r[L][j]+kk[j-n]){
					dis[j]=r[L][j]+kk[j-n];
					if(kb[j-n]==0){
						kk[j-n]=0;
						kb[j-n]=1;
						count--;
					}
					
				}
			}
			
		}
		if(count==n-1){
			break;
		}
	}
//	cout<<endl;
	long long ans=0;
	for(int i=2;i<=n;i++){
//		cout<<dis[i]<<" ";
		ans+=dis[i];
	}
	for(int i=n+1;i<=n+k;i++){
		if(kb[i-n]==1){
//			cout<<dis[i]<<" ";
			ans+=dis[i];
		}
	}
	cout<<ans;
	cin.close();
	cout.close();
	return 0;
}
