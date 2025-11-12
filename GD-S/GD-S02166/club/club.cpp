#include<bits/stdc++.h>
using namespace std;
int t,n,ans,p;
int a[101010][4],k[101010];
int s[4][101010];
int len[4];
bool cmp(int x,int y){
	return a[x][p]>a[y][p]; 
}
bool cmp2(int x,int y){
	return x>y; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		len[1]=len[2]=len[3]=ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				s[1][++len[1]]=i;
			}
			else if(a[i][2]>a[i][3]){
				s[2][++len[2]]=i;
			}
			else s[3][++len[3]]=i;
		}
		for(int i=1;i<=3;i++){
			p=i;
			sort(s[i]+1,s[i]+len[i]+1,cmp);
		}
//		for(int i=1;i<=3;i++){
//			cout<<i<<":";
//			for(int j=1;j<=len[i];j++)cout<<s[i][j]<<" ";
//			cout<<endl;
//		}
		for(int i=1;i<=3;i++){
			for(int j=1;j<=len[i];j++){
//				cout<<s[i][j]<<" "<<a[s[i][j]][i]<<endl;
				ans+=a[s[i][j]][i];
			}
			if(len[i]>n/2){
				for(int j=1;j<=len[i];j++){
					if(i==1)k[j]=a[s[i][j]][i]-max(a[s[i][j]][2],a[s[i][j]][3]);
					if(i==2)k[j]=a[s[i][j]][i]-max(a[s[i][j]][1],a[s[i][j]][3]);
					if(i==3)k[j]=a[s[i][j]][i]-max(a[s[i][j]][2],a[s[i][j]][1]);
				}
				sort(k+1,k+len[i]+1,cmp2);
				for(int j=n/2+1;j<=len[i];j++){
//					cout<<ans<<" "<<k[j]<<endl;
					ans-=k[j];
				}
			}
		}
//		for(int i=1;i<=len[3];i++)cout<<k[i]<<endl;
		printf("%d\n",ans);
	}
	
	return 0;	
} 
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
147325
*/
