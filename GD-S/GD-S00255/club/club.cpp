#include<bits/stdc++.h>
using namespace std;
struct student{
	int a,id,p;
}f[500005];
bool cmp(student x,student y){
	return x.a>y.a;
}
string vis[5000000];int h[5],o,n;
void dfs(int x,string y){
	if(x==n){vis[o++]=y;return ;}
	for(int i=1;i<=3;i++){
		if(h[i]*2<n){
			h[i]++;
			dfs(x+1,y+(to_string(i)));
			h[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int abcd;
	cin>>abcd;
	while(abcd--){
		cin>>n;
		if(n<=30){
			int a[50][5],ma=0;
			for(int i=0;i<n;i++){
				cin>>a[i][1]>>a[i][2]>>a[i][3];
			}dfs(0,"");
			for(int i=0;i<o;i++){
				int s=0;
				for(int j=0;j<n;j++){
					s+=a[j][vis[i][j]-48];
				}
				ma=max(s,ma);
			}
			cout<<ma<<endl;;
		}
		else{
			for(int i=0;i<n;i++){
				cin>>f[i*3].a>>f[i*3+1].a>>f[i*3+2].a;
				f[i*3].id=i;
				f[i*3+1].id=i;
				f[i*3+2].id=i;
				f[i*3].p=1;
				f[i*3+1].p=2;
				f[i*3+2].p=3;
			}
			sort(f,f+n*3,cmp);
			int as[5]={n/2,n/2,n/2,n/2,n/2};
			long long sum=0;
			bool ids[100005];
			memset(ids,0,sizeof(ids));
			for(int i=0;i<n*3;i++){
				student t=f[i];
				if(as[t.p]){
					if(!ids[t.id]){
						sum+=t.a;
						as[t.p]--;
						ids[t.id]=1;
					}
				}
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}

