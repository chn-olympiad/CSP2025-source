#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		int sz[100100][5];
		cin>>n;
		int x=n/2;
		for(int j=1;j<=n;j++){
			cin>>sz[j][1]>>sz[j][2]>>sz[j][3];
		}
		if(x==1){
			int a=sz[1][1]+sz[2][2];
			int b=sz[1][1]+sz[2][3];
			int c=sz[1][2]+sz[2][1];
			int d=sz[1][2]+sz[2][3];
			int e=sz[1][3]+sz[2][1];
			int f=sz[1][3]+sz[2][2];
			cout<<max(a,max(b,max(c,max(d,max(e,f)))))<<endl;
		}else if(x==2){
			int ans[100],js=0;
			for(int i1=1;i1<=3;i1++){
				for(int i2=1;i2<=3;i2++){
					for(int i3=1;i3<=3;i3++){
						for(int i4=1;i4<=3;i4++){
							if(i1==i2&&i2==i3){
								continue;
							}else if(i1==i3&&i3==i4){
								continue;
							}else if(i1==i2&&i2==i4){
								continue;
							}else if(i2==i3&&i3==i4){
								continue;
							}else{
								ans[js]=sz[1][i1]+sz[2][i2]+sz[3][i3]+sz[4][i4];
								js++;
							}
						}
					}
				}
			}
			sort(ans,ans+js);
			cout<<ans[js-1]<<endl;
		}
	}
	return 0;
}
