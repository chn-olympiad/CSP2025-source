#include<bits/stdc++.h>
using namespace std;
int b[3][1010000],bh[1010000],js[10];
unsigned long long ansl=1145141919810;
int fa[10100];
int sum=0,xb=0;
int cmp(int x,int y){
	return b[2][x]<b[2][y];
}
int father(int x){
	if(fa[x]==x){
		return x;
	}
	fa[x]=father(fa[x]);
	return fa[x];
}
//
unsigned long long cl(int v,int m,int n){
	unsigned long long ans=0;
	sum=n-1+v;
	m+=n*v;
	int bf=v,fw=0;
	while(bf>0){
		ans+=js[fw];
		bf--;
		fw++;
	}
	for(int i=0;i<n+10;i++){
		fa[i]=i;
	}
//	cout<<sum<<" "<<ans<<" "<<m<<"{"<<endl;
	for(int i=0;i<m;i++){
		bh[i]=i;
	}
	sort(bh,bh+m,cmp);
//	for(int i=0;i<m;i++){
//		cout<<bh[i];
//	}
//	cout<<endl;
	for(int i=0;i<m;i++){
		int x=b[0][bh[i]],y=b[1][bh[i]];
		if(father(x)!=father(y)){
			ans+=b[2][bh[i]];
			fa[fa[x]]=fa[y];
			sum--;
//			cout<<x<<"!"<<y<<" "<<ans<<endl;
		}else{
//			cout<<x<<"&"<<y<<endl;
		}
		if(ans>=ansl){
			return 1145141919810;
		}
		if(sum==0){
//			cout<<endl<<"Answer:"<<ans<<endl<<"}"<<endl;
			return ans;
		}
	}
	return 2147483647;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>b[0][i]>>b[1][i]>>b[2][i];
		b[0][i]--;
		b[1][i]--;
		bh[i]=i;
	}
	for(int i=0;i<k;i++){
		cin>>js[i];
		for(int j=1;j<=n;j++){
			int xb=m+n*i+j;
			b[0][xb]=i+n+1;
			b[1][xb]=j-1;
			cin>>b[2][xb];
		}
	}
//	for(int i=0;i<m+n*k;i++){
//		cout<<b[0][i]<<" "<<b[1][i]<<" "<<b[2][i]<<endl;
//	}
	for(int i=0;i<k;i++){
		ansl=min(ansl,cl(i,m,n));
	}
	cout<<ansl;
}
/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
*/
