#include<bits/stdc++.h>
using namespace std;
int c,s,q,n,a[2009][1001][2],b[200002][3],ans[200002],j,t,t1,j1,t2,t11;
char a1[200002][2][1001],b1[200002][2][1001];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a1[i][0]>>a1[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>b1[i][0]>>b1[i][1];
	}
	for(int i=1;i<=n;i++){
		for(j=0;1<=a1[i][0][j]&&a1[i][0][j]<=150;j++){
			if(a1[i][0][j]=='b'){
				t=j;
			}
			else if(a1[i][1][j]=='b'){
				t1=j;
			}
		}
		a[t1-t+1000][0][0]++;
		a[t1-t+1000][a[t1-t+1000][0][0]][0]=t;
		a[t1-t+1000][a[t1-t+1000][0][0]][1]=j;
	}
	for(int i=1;i<=q;i++){
		for(j1=0;1<=b1[i][0][j1]&&b1[i][0][j1]<=150;j1++){
			if(b1[i][0][j1]=='b'){
				t2=j1;
			}
			else if(b1[i][1][j1]=='b'){
				t11=j1;
			}
		}
		b[i][0]=t11-t2;
		b[i][1]=t2;
		b[i][2]=j1;
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=a[b[i][0]+1000][0][0];j++){
			if(a[b[i][0]+1000][j][0]<=b[i][1]&&a[b[i][0]+1000][j][1]-a[b[i][0]+1000][j][0]<=b[i][2]-b[i][1]){
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
