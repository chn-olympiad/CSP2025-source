#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
int a[4][MAXN];//地j人对i部门映象 
int ans;
int t,n,num;
bool isa = true;//满足特殊性质A 
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[j][i];
				if(a[j][i]==0) num++;
			}
			if(num<2) isa=false;
			num=0;
		}
		if(isa){
			for(int i=1;i<=3;i++){
				sort(a[i]+1,a[i]+n+1,cmp);
				for(int j=1;j<=n/2;j++){
					ans+=a[i][j];
				}
			}
		}
		t--;
	}
	cout<<ans;
	return 0;
} 
