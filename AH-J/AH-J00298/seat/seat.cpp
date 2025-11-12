#include<bits/stdc++.h>
using namespace std;
int a[11][11];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b[n*m],cnt=0;
	for(int i=0;i<n*m;i++){
		cin>>b[i];
		cnt++;
	}int c=b[0];
	sort(b,b+cnt,cmp);
	cnt=0;
	for(int i=1;i<=n;i++){
		int j=1;
		if(i%2==0)j=m;
		for(;(j<=m&&i%2==1)||(j>=1&&i&2==0);){
			a[i][j]=b[cnt];
			cnt++;
			if(a[i][j]==c){
				printf("%d %d",i,j);
				return 0;
			}if(j<=m&&i%2==1)j++;
            if(j>=1&&i&2==0)j--;
		}
	}return 0;
}
