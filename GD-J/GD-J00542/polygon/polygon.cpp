#include<bits/stdc++.h>
using namespace std;
long long a[100100],b[100100],c[100010];//a为所有小木棒 b为小木棒使用情况 c为回溯存档	
long long ans=0;//答案 
int n;//总数量 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.ont","w",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){//使用几根小木棒 
		int cx=0,he=0,maxx=0;//cx为已有小木棒数量 he为长度和 maxx为最长小木棒 
		for(int j=1;j<=n;j++){//搜索 
			if(b[j]!=1){//如果没用过 
				b[j]=1;//标记为用过 
				cx++;
				c[cx]=j;//存档 
				he+=a[j];//加入总长度 
				maxx=a[j];//取最大值 
			}
			if(cx==i){//达到本次数量 
				if(he>maxx*2){//判断是否符合条件 
					ans=(ans+1)%998244353;
				}
				if(c[cx]-cx+i+1<=n){//如果没有到第n项 
					b[cx]=0;//将最后一项标记为没用过 
					cx--;//最后一项弹出 
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
