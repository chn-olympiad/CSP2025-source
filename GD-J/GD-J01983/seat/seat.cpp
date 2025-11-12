#include<bits/stdc++.h>
using namespace std;
const int N=10001;
struct n{
	long long num,id;
}a[N];
long long k[N][N];
bool cmp(n &y,n &u){
	if(y.num==u.num){
		return y.id<u.id;
	}return y.num>u.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].id=i;
	}
	int o=0,p=a[1].num;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				o++;
				k[j][i]=a[o].num;
			}	
		}else{
			for(int j=1;j<=n;j++){
				o++;
				k[j][i]=a[o].num;
			}	
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(k[i][j]==p){
				cout<<j<<" "<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
} 
