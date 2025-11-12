#include<bits/stdc++.h>
using namespace std;
struct asd{
	int x,y,z;
}a[100005];
int n,m,kk[100005],cnt,sj[100005],jycnnt,ans,cnnt,k;
bool cmp(asd X,asd Y){
	return X.z<Y.z;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>kk[i];
		} 
	}
	cnt=1;
	while(cnnt!=n){
		cnnt=0;
		ans+=a[cnt].z;
		sj[a[cnt].x]=1;
		sj[a[cnt].y]=1;
		for(int i=1;i<=n;i++){
			if(sj[i]!=0){
				cnnt++;
			}
		}
		if(jycnnt==cnnt){
			ans-=a[cnt].z;
		}
		jycnnt=cnnt;
		cnt++;
	}
	cout<<ans<<endl;
	return 0;
}
