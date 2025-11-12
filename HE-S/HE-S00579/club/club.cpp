#include<bits/stdc++.h> 
using namespace std;
int T;
int n;
int a[100010][4];
struct edge{
	int num;
	int x;
}; 
int m1[100010],m2[100010],m3[100010];
int cnt[100010],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(m1,0,sizeof(m1));
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				m1[i]=max(m1[i],a[i][j]);
			}
		}
		sort(m1+1,m1+n+1);
		for(int i=n;i>n/2;i--){
			ans+=m1[i];
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
}
