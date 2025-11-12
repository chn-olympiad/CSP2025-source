#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n;
int arr[200005][3];
struct change{
	int id,cost;
}c[200005];
bool cmp(change xx,change yy){
	return xx.cost<yy.cost;
}
int clubs[3][200005],top[3];
int ans=0; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		top[0]=top[1]=top[2]=0;
		ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			int maxv=-1,maxid,minv=0x7777777f;
			for(int j=0;j<3;j++){
				scanf("%d",&arr[i][j]);
				minv=min(minv,arr[i][j]);
				if(arr[i][j]>maxv){
					maxv=arr[i][j];
					maxid=j;
				}
			}
			clubs[maxid][top[maxid]++]=i;
			ans+=maxv;
			int sec=arr[i][0]+arr[i][1]+arr[i][2]-maxv-minv;
			c[i].cost=maxv-sec;
			c[i].id=maxid;
		}
		for(int k=0;k<3;k++){
			if(top[k]>n/2){
				sort(c,c+n,cmp);
				//for(int ab=0;ab<n;ab++)cout<<c[ab].id<<' '<<c[ab].cost<<endl;
				//cout<<"\n-----\n";
				int i=0;
				while(top[k]>n/2){
					//cout<<c[i].cost<<' '<<c[i].id<<' '<<i<<endl;
					if(c[i].id==k){
						ans-=c[i].cost;
						top[k]--;
					}
					i++;
				}
				break;
			}
			
		}
		printf("%d\n",ans);
	}
	return 0;
}



// it fking hard!
