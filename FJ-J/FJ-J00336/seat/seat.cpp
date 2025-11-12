#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 12;
//8:43 opening
//8:46 coding
//9:07 coded!
//预计100分 
int n,m,a[N*N],b[N*N],s[N][N],cnt=0,R;
bool cmp(int a,int b){
	return a>b;
}
bool cmp2(int a,int b){
	return a<b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	//排完序后降序  
	//s[i][j]：第i列第j行 
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==1){
				s[j][i]=a[++cnt];
			}
			else{
				s[n-j+1][i]=a[++cnt];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[i][j]==R){
				cout<<j<<' '<<i;
			}
		}
	}
	return 0;
}
