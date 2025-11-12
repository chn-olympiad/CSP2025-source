//GZ-S00474 贵阳市第三实验中学 陈泰锡
#include <bits/stdc++.h>
using namespace std;
int a[100002][4];
int b[100002],c[3];
int n,m,s;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&m);
	int ma=0,ans=0;
	for(int k=0;k<m;k++){
		scanf("%d",&n);
		if(n%2!=0||n<2||n>10000){
			return 0;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				scanf("%d",&s);
				a[i][j]=s;
				if(ma<a[i][j]){
					ma=a[i][j];
				}
			}
			ans+=ma;
			ma=0;
		}
		b[k]=ans;
		ans=0;
	}
	for(int i=0;i<m;i++){
		cout<<ans<<endl;
	}
	return 0;
}
