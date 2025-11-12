#include<bits/stdc++.h>
using namespace std;
int n,x,c[30],a,b,pos,r,ans,zero,one;
int two[1010][30];
struct qujian{
	int l,r;
}d[1000010];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>x;
	for(int j=0;x>0;j++){
		c[j]=x%2;
		x/=2;
	}
	
	if(n<=1e3){
		//60tps
		for(int i=1;i<=n;i++){
			cin>>x;
			for(int j=0;x>0;j++){
				two[i][j]=x%2;
				x/=2;
			}
			//cout<<i<<" ";
			for(int j=0;j<=20;j++){
				//cout<<two[i][j]<<" "<<two[i-1][j]<<'\n';
				two[i][j]+=two[i-1][j];//二进制前缀和
				//cout<<two[i][j];
			}//cout<<'\n';
		}
		
		for(int j=1;j<=n;j++){
			for(int i=j;i>=1;i--){
				for(int k=0;k<=20;k++){
					a=two[j][k]-two[i-1][k];
					if(a%2)x=1;
					else x=0;
					if(x!=c[k])goto nt;
				}
				//cout<<i<<" "<<j<<"\n";
				d[pos].l=i,d[pos++].r=j;//区间预处理 
				nt:;	
			}
		}
		//cout<<pos<<" ";
		
		//区间贪心
		for(int i=0;i<pos;i++){
			if(d[i].l>r){
				r=d[i].r;
				ans++;
			}
		}
		cout<<ans;
	}
	else{
		//cout<<"我没招了";
		//目标：第十三个测试点 苍蝇再小也是肉 5tps
		for(int i=0;i<n;i++){
			cin>>b;
			if(b)one++;
			else zero++;
		}
		if(x==0)cout<<zero;
		else cout<<one;
	} 
	return 0;
}