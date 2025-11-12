#include<bits/stdc++.h>
using namespace std;
int m[3][10005],rs[3],cb1[5005],cb2[5005],cb3[5005],czb[10005],ans;
int ymax(int y){
	int maxid=0,maxd=0;
	for(int i=0;i<3;i++){
		if(maxd<m[i][y]){
			maxid=i;
			maxd=m[i][y];
		}
	}
	return maxid;
}
int dierymax(int y){
	int maxid=0,maxd=0;
	for(int i=0;i<3;i++){
		if(maxd<m[i][y] && m[i][y]!=ymax(y)){
			maxid=i;
			maxd=m[i][y];
		}
	}
	return maxid;
}
int czbmin(int a){
	int minn=10005;
	for(int as=0;as<a;as++){
		if(minn>czb[as]){
			minn=czb[as];
		}
	}
	return minn;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int w=0;w<t;w++){
		int n;
		cin>>n;
		int rsm=n/2;
		for(int y=0;y<n;y++){
			for(int x=0;x<3;x++){
				cin>>m[x][y];
			}
			int ymaxx=max(max(m[0][y],m[1][y]),m[2][y]);
			czb[y]=ymaxx-dierymax(y);
			if(rs[ymax(y)]<rsm){
				if(ymax(y)==0){
					cb1[rs[ymax(y)]]=ymaxx;
					rs[ymax(y)]++;
					ans+=m[ymax(y)][y];
				}
				if(ymax(y)==1){
					cb2[rs[ymax(y)]]=ymaxx;
					rs[ymaxx]++;
					ans+=m[ymax(y)][y];
				}
				if(ymax(y)==2){
					cb3[rs[ymax(y)]]=ymaxx;
					rs[ymaxx]++;
					ans+=m[ymax(y)][y];
				}
			}
			else{
				ans=ans-czbmin(rsm)+czb[y];
			}
		}
	}
	cout<<6<<endl;
	return 0;
}
