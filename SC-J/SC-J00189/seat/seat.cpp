#include<bits/stdc++.h>
using namespace std;
int n,m,f,a[1010],b[110][110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++) cin >> a[i];
	f=a[1];
	sort(a+1,a+n*m+1,cmp);
	int flag=0,cnt=0;
	for(int i=1;i<=m;i++){
		if(!flag){
			for(int j=1;j<=n;j++){
				b[i][j]=a[++cnt];
				if(b[i][j]==f) cout << i << " " << j;
			}
			flag=1;
		}
		else{
			for(int j=n;j>=1;j--){
				b[i][j]=a[++cnt];
				if(b[i][j]==f) cout << i << " " << j;
			}
			flag=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}