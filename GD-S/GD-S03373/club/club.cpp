#include<bits/stdc++.h> 
using namespace std;
const int MAX=100005;
int n;
int a[MAX][3],rak[MAX][2];
bool ii[MAX][3];
int num[3],ans[3],minn[3],mif[3],re[MAX];

void work(int x,int st){
	num[st]++;
	ii[x][st]=1;
	re[x]+=re[x-1]+a[x][st];
}

void wok(int x){
	if(x>=1){
		wok(x-1);
		int st=rak[x][0],nd=rak[x][1];
		if(num[st]+1<=n/2){
			work(x,st);
		}else{
			int mm=re[x-1]+a[x][nd],nn;
			int ma=-1e9,ff,nez;
			for(int i=1;i<x;i++){
				if(ii[i][rak[i][st]]==0){
					break;
				}
				int ne=a[i][st];
				int ne2=a[i][nd];
				nez=ne2-ne;
				if(ne>ma){
					ff=i;
					ma=ne;
				}
			}
			nn=re[x-1]+a[x][nd]+ma;
			if(mm>nn){
				work(x,nd);
			}else{
				num[rak[ff][1]]++;
				ii[x][st]=1;
				ii[ff][st]=0;
				ii[ff][rak[ff][1]]=1;
				re[x]=nn;
			}
		}
	}
}

void got(){
	for(int i=1;i<=n;i++){
		pair<int,int> b[3];
		for(int j=0;j<3;j++){
			b[j].first=a[i][j];
			b[j].second=j;
		}
		sort(b,b+3);
		rak[i][1]=b[1].second;
		rak[i][0]=b[2].second;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		for(int i=0;i<3;i++){
			num[i]=0;
			ans[i]=0;
			minn[i]=1e9;
			mif[i]=1e9;
		}
		memset(ii,0,sizeof(ii));
		memset(re,0,sizeof(re));
		got();
		re[0]=0;
		wok(n);
		cout<<re[n]<<"\n";
	}
	return 0;
}
