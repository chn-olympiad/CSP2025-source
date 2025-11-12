#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],dir;
bool cmp(int x,int y){
	return y<x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int sum=a[1],cnt=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;){
		for(int j=1;j<=m;){
			if(a[cnt]==sum){
				cout<<j<<" "<<i;
				return 0;
			}
			if(dir==0&&i==n){
				j++;
				dir=1;
			}else if(dir==1&&i==1){
				j++;
				dir=0;
			}else if(dir==0){
				i++;
			}else{
				i--;
			}
			cnt++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
