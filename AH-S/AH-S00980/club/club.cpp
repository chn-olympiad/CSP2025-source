#include<bits/stdc++.h>
using namespace std;
int T,n,num[5],tmp1,tmp2,maxm,maxn,ans,re,now;
bool ff;
struct Node{
	int a[5];
	int d;
	int e;
}a[100005];
bool f(int y,int x){
	bool flag=true;
	for(int i=1;i<=3;i++)
		if(a[y].a[x]<a[y].a[i]){
			flag=false;
			break;
		}
	if(!flag)
		return false;
	a[y].e=x;
	num[x]++;
	ans+=a[y].a[x];
	return true;
}
bool cmp(Node x,Node y){
	return x.d<y.d;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		num[1]=num[2]=num[3]=0;
		ans=0;
		maxn=maxm=-1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a[1]>>a[i].a[2]>>a[i].a[3];
			for(int j=1;j<=3;j++)
				if(f(i,j))
					break;
		}
		for(int i=1;i<=3;i++)
			if(num[i]>maxn){
				maxn=num[i];
				maxm=i;
			}
		for(int j=1;j<=n;j++){
			ff=false;
			for(int i=1;i<=3;i++)
				if(i!=maxm){
					if(!ff){
						tmp1=a[j].a[maxm]-a[j].a[i];
						ff=true;
					}
					else
						tmp2=a[j].a[maxm]-a[j].a[i];
				}
			a[j].d=min(tmp1,tmp2);
		}
		if(maxn<=n/2){
			cout<<ans<<'\n';
			continue;
		}
		sort(a+1,a+1+n,cmp);
		re=maxn-n/2,now=1;
		while(re){
			if(a[now].e==maxm){
				ans-=a[now].d;
				re--;
			}
			now++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
