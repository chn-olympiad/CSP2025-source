#include<bits/stdc++.h>
using namespace std;
long long n,m,seat[15][15],x;
struct Node{
	char name[1];
	long long point;
}a[105],b[105];
long long cmp(Node a,Node b){
	return a.point>b.point;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=m*n;i++){
		cin>>a[i].point;
		if(i==1){
			a[i].name[0]='R';
		}else{
			a[i].name[0]='a';
		}
	}sort(a+1,a+n*m+2,cmp);
	for(long long i=1;i<=m;i++){
		if(i%2==1){
			for(long long j=1;j<=n;j++){
				x++;
				if(a[x].name[0]=='R'){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(long long j=n;j>=1;j--){
				x++;
				if(a[x].name[0]=='R'){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
