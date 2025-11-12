//GZ-S00107 贵阳市第一中学 周晓凡
#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		if(n==2){
			int a[4];
			int b[4];
			cin>>a[1]>>a[2]>>a[3];
			cin>>b[1]>>b[2]>>b[3];
			int maxn=0;
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					maxn=max(a[j]+b[k],maxn);
				}
			}
			cout<<maxn;
		}else{
			for(int j=1;j<=n;j++){
				int x,y,z;
				cin>>x>>y>>z;
				a[j]=x;
			}
			int cnt=0;
			sort(a+1,a+n+1,cmp);
			for(int j=1;j<=n/2;j++){
				cnt+=a[j];
			}
			cout<<cnt<<endl;
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
