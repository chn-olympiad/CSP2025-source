#include<bits/stdc++.h>
using namespace std;
int b[20][20];
int a[1000];
int sum,cnt=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int sum =a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==1){
				b[j][i]=a[cnt];
				cnt++;
				if(b[j][i]==sum){
					cout<<i<<" "<<j;
				}
			}
			else {
				int l =n;
				int r =n;
				b[l][i] =a[cnt];
				if(b[l][i]==sum){
					cout<<i<<" "<<l;
				}
				l--;
				cnt++;
			}
		}
	}
	return 0;
}
