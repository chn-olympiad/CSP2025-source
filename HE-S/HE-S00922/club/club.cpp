#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][5],to[5],ans,ch[N],idx[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0;
		to[1]=to[2]=to[3]=0;
		for(int i=1;i<=n;i++) {
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			idx[i]=1;
			if(a[i][2]>a[i][1]) swap(a[i][1],a[i][2]),idx[i]=2;
			if(a[i][3]>a[i][1]) swap(a[i][1],a[i][3]),idx[i]=3;
			if(a[i][2]<a[i][3]) swap(a[i][2],a[i][3]);
			to[idx[i]]++;
			ans+=a[i][1];
			ch[i]=a[i][1]-a[i][2];
		//	cout<<ch[i]<<'\n';
		}
		int cnt=1;
		for(int i=1;i<=3;i++){
			if(to[i]>(n>>1)){
				for(int j=1;j<=n;j++)
					if(idx[j]!=i) ch[j]=1e9;
				sort(ch+1,ch+n+1);
			}
			while(to[i]>(n>>1)){
			//	cout<<to[i]<<' '<<i<<'\n';
				//cout<<ch[cnt]<<'\n';
				to[i]--;
				ans-=ch[cnt++];
			}
		}
		printf("%d\n",ans);
	}
} 
/*
2
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0*/
