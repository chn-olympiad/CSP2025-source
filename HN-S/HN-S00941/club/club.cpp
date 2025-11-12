#include<bits/stdc++.h>
using namespace std;
struct stu{
	int a,b,c;
}d[100007];
int ans[4],e[4][3];
bool cmp(stu x,stu y){
	if(x.a>y.a)return 1;
	else if(x.a<y.a)return 0;
	if(x.b>y.b)return 1;
	else if(x.b<y.b)return 0;
	if(x.c>y.c)return 1;
	return 0;
}
int judge1(stu x,int i){
	if(i==1)return x.a;
	if(i==2)return x.b;
	return x.c;
}
int judge2(int p,int q){
	if(p==1&&q==2)return 3;
	if(p==1&&q==3)return 2;
	return 1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int h=n/2;
		int cnt=0;
		ans[1]=0;ans[2]=0;ans[3]=0;
		for(int i=1;i<=n;i++)cin>>d[i].a>>d[i].b>>d[i].c;
		sort(d+1,d+1+n,cmp);
		for(int i=1;i<=n;i++){
			e[1][1]=d[i].a;
			e[2][1]=d[i].b;
			e[3][1]=d[i].c;
			e[1][2]=1;
			e[2][2]=2;
			e[2][3]=3;
			for(int j=2;j>=1;j--){
				for(int k=1;k<=i;k++){
					if(e[k][1]<e[k+1][1]){
						swap(e[k][1],e[k+1][1]);
						swap(e[k][2],e[k+1][2]);
					}
				}
			}
			for(int j=1;j<=3;j++){
				if(ans[e[j][2]]<h){
					ans[e[j][2]]++;
					cnt+=e[j][1];
					break;
				}
			}
		}
	    cout<<cnt<<'\n';
	}
	return 0;
}
