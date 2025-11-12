//GZ-S00322 北京师范大学贵阳附属中学 王明轩 
#define max1(a,b,c) (a>b?a:b)>(b>c?b:c)?(a>b?a:b):(b>c?b:c)
#define max2(a,b) (a>b?a:b)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int t; 
int ans[10];
int n;
int a[100010][4];
vector<int>club1;
vector<int>club2;
vector<int>club3;
bool cmp1(int x,int y){
	int cx=a[x][1] - max2(a[x][2],a[x][3]);
	int cy=a[y][1] - max2(a[y][2],a[y][3]);
	return cx<cy;
}
bool cmp2(int x,int y){
	int cx=a[x][2] - max2(a[x][1],a[x][3]);
	int cy=a[y][2] - max2(a[y][1],a[y][3]);
	return cx<cy;
}
bool cmp3(int x,int y){
	int cx=a[x][3] - max2(a[x][2],a[x][1]);
	int cy=a[y][3] - max2(a[y][2],a[y][1]);
	return cx<cy;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		club1.clear();
		club2.clear();
		club3.clear();
		cin>>n;
		for(int j=1;j<=n;j++){
			scanf("%d%d%d",&a[j][1],&a[j][2],&a[j][3]);
			int maxx=max1(a[j][1],a[j][2],a[j][3]);
			if(maxx==a[j][1])club1.push_back(j);
			else if(maxx==a[j][2])club2.push_back(j);
			else club3.push_back(j);
		}
		if(club1.size()>n/2){
			sort(club1.begin(),club1.end(),cmp1);
			for(int j=0;j<club1.size()-n/2;j++){
				if(a[club1[j]][2]>a[club1[j]][3]){
					club2.push_back(club1[j]);
				}
				else club3.push_back(club1[j]);
				club1[j]=0;
			}
		}
		if(club2.size()>n/2){
			sort(club2.begin(),club2.end(),cmp2);
			for(int j=0;j<club2.size()-n/2;j++){
				if(a[club2[j]][1]>a[club2[j]][3]){
					club1.push_back(club2[j]);
				}
				else club3.push_back(club2[j]);
				club2[j]=0;
			}
		}
		if(club3.size()>n/2){
			sort(club3.begin(),club3.end(),cmp3);
			for(int j=0;j<club3.size()-n/2;j++){
				if(a[club3[j]][1]>a[club3[j]][2]){
					club1.push_back(club3[j]);
				}
				else club2.push_back(club3[j]);
				club3[j]=0;
			}
		}
		for(int j=0;j<club1.size();j++){
			ans[i]+=a[club1[j]][1];
		}
		for(int j=0;j<club2.size();j++){
			ans[i]+=a[club2[j]][2];
		}
		for(int j=0;j<club3.size();j++){
			ans[i]+=a[club3[j]][3];
		}
	}
	for(int i=1;i<=t;i++)printf("%d\n",ans[i]);
	return 0;
}
