#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200];
int mp[20][20];
int R;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;i++){
		scanf("%d",&a[i]);
	}
	R=a[0];
	string dir="up";
	int pointer=0;
	sort(a,a+(n*m),cmp);
	for(int i=1;i<=m;i++){
		if(dir=="up"){
			for(int j=1;j<=n;j++){
				mp[j][i]=a[pointer++];
				if(mp[j][i]==R){
					printf("%d %d",i,j);
					return 0;
				}
			}
			dir="down";
		}else{
			for(int j=n;j>=1;j--){
				mp[j][i]=a[pointer++];
				if(mp[j][i]==R){
					printf("%d %d",i,j);
					return 0;
				}
			}
			dir="up";
		}
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}
