#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int zj = a[1];
	sort(a+1,a+n*m+1,cmp);
	int cnt=0;
	int nn,mm;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cnt++;
			if(a[cnt]==zj){
				nn = i;
				if(nn%2==1)mm = j;
				else mm = m-j+1;
				cout<<nn<<" "<<mm;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
