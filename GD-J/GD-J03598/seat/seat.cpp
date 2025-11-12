#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int n,m,a[1005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int ex;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
		if (i==1) ex=a[1];
	}
	sort(a+1,a+n*m+1,cmp);
	int cnt=0;
	for (int i=1;i<=m;i++){
		if (i&1){
			for (int j=1;j<=n;j++){
				if (a[++cnt]==ex){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for (int j=n;j>=1;j--){
				if (a[++cnt]==ex){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
