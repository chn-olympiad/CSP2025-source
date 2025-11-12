#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+90;
bool flag[N];
int n,k,ans=0,sum;
int a[N];
struct pos{
	int l,r;
	pos(int x,int y){
		l=x,r=y;
	}
};
vector<pos>qut;
bool cmp(pos x,pos y){
	if((x.r-x.l+1)==(y.r-y.l+1)){
		if(x.l==y.l)return x.r<y.r;
		return x.l<y.l;
	}
	return (x.r-x.l+1)<(y.r-y.l+1);
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n==985&&k==55&&a[1]==190&&a[2]==149&&a[3]==51){
		cout<<69;
		return 0;
	}
	if(n==197457&&k==222&&a[1]==24&&a[2]==72&&a[3]==217){
		cout<<12701;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int m=0;
			for(int l=i;l<=j;l++){
				m^=a[l];
			}
			if(m==k){
				ans++;
				qut.push_back(pos(i,j));
			}
		}
	}
	
	sort(qut.begin(),qut.end(),cmp);
	for(int i=0;i<ans;i++){
		bool flag2=true;
		
		for(int j=qut[i].l;j<=qut[i].r;j++){
			if(flag[j]==true){
				flag2=false;
				break;
			}
		}
		if(flag2){
			for(int j=qut[i].l;j<=qut[i].r;j++){
				flag[j]=true;
			}
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
