#include<bits/stdc++.h>
using namespace std;
int n,a[1005][1005],m,sum[100005],cnt=1;
bool cmp(int x,int y){
	return x>y;
}
void tian(){
	int cnt=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[j][i]=cnt++;
			}
		}else if(i%2==0){
				for(int j=n;j>=1;j--){
					a[j][i]=cnt++;
				}
			}
	}
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
	cin>>sum[i];
}int pos=sum[1];
sort(sum+1,sum+n*m+1,cmp);
tian();
int pos1;
for(int i=1;i<=n*m;i++){
	if(sum[i]==pos){
		pos1=i;
	}
}for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		if(a[i][j]==pos1){
			cout<<j<<" "<<i;
		exit(0);
		}
	}
}
fclose(stdin);
fclose(stdout);
	return 0;
}
