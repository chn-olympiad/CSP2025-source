#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1010];
	int cnt=1;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(a[0]<a[i]){
			cnt++;
			if(cnt%m==0){
				cout<<cnt/m<<" "<<cnt;
			}else if(cnt%m!=0&&(cnt/n+1)%2!=0){
				cout<<cnt/m+1<<" "<<cnt%n;
			}else if(cnt%m!=0&&(cnt/n+1)%2==0){
				cout<<cnt/m+1<<" "<<cnt/n+1;
			}
		}
	}
	return 0;
}
