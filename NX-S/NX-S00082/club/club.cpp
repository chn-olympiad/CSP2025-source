#include<bits/stdc++.h>
using namespace std;
struct node{
	long long shuju;
	long long biaohao;
	long long shuzu;
};
bool cmp(node a,node b){
	return a.shuju<b.shuju;
}
int main(){
	freopen("club1.in","r",stdin);
	freopen("club1.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		long long m,zong=0,total[5]={0};
		cin>>m;
		node maxn[m+10],maxn1[m+10],maxn2[m+10];
		for(int i=0;i<m;i++){
			node a[5];
			cin>>a[1].shuju>>a[2].shuju>>a[3].shuju;
			a[1].biaohao=1;
			a[2].biaohao=2;
			a[3].biaohao=3;
			sort(a+1,a+4,cmp);
			maxn[i].shuju=a[3].shuju;
			maxn[i].biaohao=a[3].biaohao;
			maxn[i].shuzu=i;
			maxn1[i].shuju=a[2].shuju;
			maxn1[i].biaohao=a[2].biaohao;
			maxn1[i].shuzu=i;
			maxn2[i].shuju=a[1].shuju;
			maxn2[i].biaohao=a[1].biaohao;
			maxn2[i].shuzu=i;	
		}
		sort(maxn,maxn+m,cmp);
		for(int i=m-1;i>=0;i--){
			if(total[maxn[i].biaohao]<m/2){
				total[maxn[i].biaohao]++;
				zong+=maxn[i].shuju;

			}else if(total[maxn1[maxn[i].shuzu].biaohao]<m/2){
				total[maxn1[maxn[i].shuzu].biaohao]++;
				zong+=maxn1[maxn[i].shuzu].shuju;

			}else if(total[maxn2[maxn[i].shuzu].biaohao]<m/2){
				total[maxn2[maxn[i].shuzu].biaohao]++;
				zong+=maxn2[maxn[i].shuzu].shuju;
			}
		}
		cout<<zong<<endl;
	}
	return 0;
}
