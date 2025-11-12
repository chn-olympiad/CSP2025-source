#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][5],f[100010],s[100010],m[100010],b[10],ans[10];
struct data{
	int c,u;
}q[100010]; 
bool cmp(data x,data y){
	return x.c<y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(f,0,sizeof(f));
		memset(s,0,sizeof(s));
		memset(m,0,sizeof(m));
		memset(b,0,sizeof(b));
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++){
			int maxn=-1e9,mini=1e9; 
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>maxn){
					maxn=a[i][j];
					f[i]=j;
				}if(a[i][j]<mini){
					mini=a[i][j];
					m[i]=j;
				}
			}
			s[i]=6-f[i]-m[i];
			b[f[i]]++;
			ans[f[i]]+=a[i][f[i]];
		}
		for(int i=1;i<=3;i++){
			memset(q,0,sizeof(q));
			int k=0;
			if(b[i]>n/2){
				for(int j=1;j<=n;j++){
					if(f[j]==i){
						q[++k].c=a[j][f[j]]-a[j][s[j]];
						q[k].u=j;
					}
				}
				sort(q+1,q+k+1,cmp);
				for(int j=1;j<=b[i]-n/2;j++){
					if(b[s[q[j].u]]<n/2){
						b[s[q[j].u]]++;
						ans[s[q[j].u]]+=a[q[j].u][s[q[j].u]];
						ans[i]-=a[q[j].u][f[q[j].u]];
					}
				}
				b[i]=n/2;
			}
			memset(q,0,sizeof(q));
			k=0;
			if(b[i]>n/2){
				for(int j=1;j<=n;j++){
					if(f[j]==i){
						q[++k].c=a[j][f[j]]-a[j][m[j]];
						q[k].u=j;
					}
				}
				sort(q+1,q+k+1,cmp);
				for(int j=1;j<=b[i]-n/2;j++){
					if(b[m[q[j].u]]<n/2){
						b[m[q[j].u]]++;
						ans[m[q[j].u]]+=a[q[j].u][m[q[j].u]];
						ans[i]-=a[q[j].u][f[q[j].u]];
					}
				}
				b[i]=n/2;
			}
		}
		int last=0;
		for(int i=1;i<=3;i++)last+=ans[i];
		cout<<last<<endl;
	}
	
	return 0;
}
