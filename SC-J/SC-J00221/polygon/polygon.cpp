#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio> 
using namespace std;
int ab[2001];
int bb[507][207][107];
int mm;
int dt(int a,int s,int maxn){
	if(bb[a][s][maxn]!=-1){
			return bb[a][s][maxn];
	}

	if(a==mm+1&&s>maxn*2)
	return bb[a][s][maxn]=1;
	if(a==mm+1)
	return bb[a][s][maxn]=0;
	int ans=0;
	ans+=dt(a+1,s,maxn);
	ans=ans%998244353;
		ans+=dt(a+1,min(ab[mm]*2+1,s+ab[a]),ab[a]);
		ans%=998244353 ;
//	}	
	return bb[a][s][maxn]=ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int a,b,c,d,e,f;
    cin>>a;
    mm=a;
    for(int i=1;i<=a;i++){
    	scanf("%d",&ab[i]);
	}
	sort(ab+1,ab+a+1);
	for(int i=0;i<=a+1;i++){
		for(int j=0;j<=ab[a]*2+1;j++){
			for(int k=0;k<=ab[a];k++){
				bb[i][j][k]=-1;
			}
		} 
	}
	printf("%d",dt(1,0,0));
	return 0;
}