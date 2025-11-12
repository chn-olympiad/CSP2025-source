#include<bits/stdc++.h>
using namespace std;
int n,m,xiang[10008][10008],cun[100001]={},ans=0;
bool lianjie[10001][10001]={},cheng[100001]={};
struct lu{
	int z,l,v;
}xiu[100008];
bool cmp(lu a,lu b){
	return a.v<b.v;
}
int z1=0,l1=0,v1=2147483647,uuy;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>uuy>>n>>m;
	for(int i=0;i<n;i++){
		cin>>xiu[i].z>>xiu[i].l>>xiu[i].v;
		
	}
	sort(xiu,xiu+n,cmp);
	for(int i=1;i<=m;i++){
		cin>>cun[i];
		for(int j=0;j<n;j++){
			cin>>xiang[i][j];
		}
	}
	
	long long sum=0;
	for(int i=0;i<n;i++){
		int pre=xiu[i].v;
		for(int j=1;j<=m;j++){
			if(ans==n)break;
			if(cheng[xiu[i].l])ans--;
			if(cheng[xiu[i].z])ans--;			
					
			if(!lianjie[i][xiu[i].l]&&!lianjie[i][xiu[i].z]){
				if(pre>xiang[i][xiu[i].l]+xiang[i][xiu[i].z]){
					pre=xiang[i][xiu[i].l]+xiang[i][xiu[i].z];
					lianjie[i][xiu[i].l]=1;
					lianjie[i][xiu[i].z]=1;

				}
			}
			else if(!lianjie[i][xiu[i].l]){
					if(pre>xiang[i][xiu[i].l]){
					pre=xiang[i][xiu[i].l];
					lianjie[i][xiu[i].l]=1;
					lianjie[i][xiu[i].z]=1;	
					cheng[xiu[i].l]=1;
					cheng[xiu[i].z]=1;			
			}
		}
			else{
					if(pre>xiang[i][xiu[i].z]){
					pre=xiang[i][xiu[i].z];
					lianjie[i][xiu[i].l]=1;
					lianjie[i][xiu[i].z]=1;	
					cheng[xiu[i].l]=1;
					cheng[xiu[i].z]=1;				
			}
			
			}	
		
	}
		sum+=pre;
		ans+=2;
		}
	
	cout<<sum;
	
	return 0;
}

