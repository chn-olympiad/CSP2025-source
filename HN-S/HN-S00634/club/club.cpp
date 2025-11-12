#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;
const int N=1e5+5;
int id[5][N],len[3],maxn[N],minn[N],e[N];
bool cmp2(int x,int y){
	return maxn[x]-minn[x]>maxn[y]-minn[y];
}
void add(){
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=3;i++){
		len[i]=0;
	}
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		minn[i]=a+b+c-max(a,max(b,c))-min(a,min(b,c));
		maxn[i]=max(a,max(b,c));
		sum+=max(a,max(b,c));
		if(a>b&&a>c){
			id[1][++len[1]]=i;
		}else if(b>a&&b>c){
			id[2][++len[2]]=i; 
		}else{
			id[3][++len[3]]=i;
		}
	}
	for(int i=1;i<=3;i++){
		if(len[i]>n/2){
			for(int j=1;j<=len[i];j++){
				e[j]=id[i][j];
			} 
			sort(e+1,e+len[i]+1,cmp2);
			while(len[i]>n/2){
				sum-=maxn[e[len[i]]]-minn[e[len[i]]];
				len[i]--;
			}
			break;
		}
	}
	cout<<sum<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		add();
	}
	return 0; 
} 
