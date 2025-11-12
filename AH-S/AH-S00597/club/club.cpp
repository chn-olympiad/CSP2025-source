#include<bits/stdc++.h>
using namespace std;
int n,m;//m为单科最多人数即n/2
int a[100005][6];//下标分别含义：0为所在俱乐部，123分别为各个好感，4为替换最大值,5为替换最大值地点
int geshu[5];
int a1[4][100005];
long long int ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int tcishu;
	cin>>tcishu;
	for(;tcishu>0;tcishu--){
		cin>>n;
		m=n/2;ans=0;geshu[1]=0;geshu[2]=0;geshu[3]=0;
		for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];//以上为录入chushihua部分
		for(int i=1;i<=n;i++){
			int club,k=0;//k仅为临时作用
			for(int j=1;j<=3;j++)
			  if(a[i][j]>k){k=a[i][j];club=j;a[i][0]=club;}
			k=0;
			for(int j = 1;j <= 3;j++){
				if(club == j) continue;
				if(a[i][j] >= k){a[i][5] = j;k = a[i][j];a[i][4] = a[i][j];}
			}//以上为筛选chuli程序
			k=INT_MAX;
			if(geshu[club] == m){
				int value = a[i][club],lue = a[i][4];
				int an=value-lue;
				int baocun;
				for(int i = 1;i <= geshu[club];i++){
					int am;
					am = a[a1[club][i]][club]-a[a1[club][i]][4];//cout<<am<<"ok"<<endl;
					if(am<k){
						baocun=i;
						k=am;
					}
				}//cout<<k<<"ok"<<endl;
				if(k > an){
					ans+=lue;
				}
				else{//k<=an
					ans+=value-k;
					a1[club][baocun]=i;
				}
				continue;
			}
			geshu[club]++;
			a1[club][geshu[club]]=i;
			ans+=a[i][club];
		}
		cout<<ans<<endl;
	}
	return 0;
}
