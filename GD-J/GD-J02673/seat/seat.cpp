#include <bits/stdc++.h>
using namespace std;
bool vis[15][15];
int h[3]={1,-1,0};
int s[3]={0,0,1};
int n,m,fenshu,ans=0,a;
void find(int heng,int shu,int cnt,int num){
	if(cnt==num){
		cout<<shu<<" "<<heng<<endl;
		return;
	}
	for(int i=0;i<3;i++){
		if(heng+h[i]>0&&heng+h[i]<=n&&shu+s[i]>0&&shu+s[i]<=n&&vis[heng+h[i]][shu+s[i]]==0){
			vis[heng][shu]=1;
			return find(heng+h[i],shu+s[i],cnt+1,num);
		}
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>fenshu;
	for(int i=1;i<=n*m-1;i++){
		cin>>a;
		if(a>fenshu){
			ans++;
		}
	}
	if(ans==0){
		cout<<"1 1"<<endl;
		return 0;
	}
	int num=ans+1;
	find(1,1,1,num);
	return 0;
}
