#include<bits/stdc++.h>
using namespace std;
int T,n,ans;
int a[100005][5],b[5],c[100005];
void dfs(int x,int z){
	//cout<<"x:"<<x<<"   z:"<<z<<"\n";
	if(x==n+1){
		ans=max(ans,z);
		return;
	}
	for(int i=1;i<=3;i++){
		if(b[i]+1<=n/2){
			b[i]++;
			dfs(x+1,z+a[x][i]);
			b[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		int ch12=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==2||j==3){
					if(a[i][j]!=0) ch12=0;
				}
			}
		}
		//test 1
		if(n==2){
			ans=max(a[1][1]+a[2][2],ans);
			ans=max(a[1][1]+a[2][3],ans);
			ans=max(a[1][2]+a[2][1],ans);
			ans=max(a[1][2]+a[2][3],ans);
			ans=max(a[1][3]+a[2][1],ans);
			ans=max(a[1][3]+a[2][2],ans);
			cout<<ans<<"\n";
		}
		//test 2-8
		else if(n<=30){
			dfs(1,0);
			cout<<ans<<"\n";
			b[0]=0;b[1]=0;b[2]=0;b[3]=0;b[4]=0;b[5]=0;
		}
		//test 12
		else if(ch12==1){
			for(int i=1;i<=n;i++){
				c[i]=a[i][1];
			}
			sort(c+1,c+n+1);
			for(int i=n;i>=n/2+1;i--){
				ans+=c[i];
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

10
3 2 0
1 4 0
5 6 0/
7 8 0 /
9 1 0
1 8 0/
2 4 0
9 8 0/
5 7 0/
6 3 0

1(1),1(1),1(2),2(1),2(2),3(1),3(2),4(2),4(2),5(1),5(1),6(1),6(2),7(1),7(2),8(2),8(2),8(2),9(1),9(1)

4 4
53
63
*/
