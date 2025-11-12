#include<bits/stdc++.h>
using namespace std;
int t,n,a[10005][5],b[10005][5],maxx[7]={0,0,0,0,0,0,0},ans=0,k,y,newk,newy,newa;
void dfs(int q,int sum){
	for(int i=1;i<=q;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			b[i][j]=a[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		k=-1;
		ans=0;
		for(int j=1;j<=3;j++){
			k=max(k,a[i][j]);
			y=j;
		}
		for(int z=1;z<=q;z++){
			if(k<a[z][y]){
				ans++;
			}
		}
		int e=q/2;
		if(ans<e){
			maxx[sum]+=k;
		}else{
			a[i][y]=-1;
			newk=-2;
			newa=0;
			for(int j=1;j<=3;j++){
				newk=max(k,a[i][j]);
			    newy=j;
			}
			for(int z=1;z<=q;z++){
			    if(k<a[z][newy]){
				    newa++;
			    }
		    }
		    maxx[sum]+=newk;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t>>n;
	for(int i=1;i<=t;i++){
		dfs(n,i);
	}
	for(int i=1;i<=t;i++){
		cout<<maxx[i]<<endl;
	}
	return 0;
} 
