#include<iostream>
#include<cstdio>
#include<iomanip>
#include<math.h>
#include<queue>
#include<stack>
#include<map>
#include<cstring>
#include<vector>
#include<algorithm>
#define LL long long
const int N=1e5+10;
const int Inf=0x3f3f3f3f;
using namespace std;
LL c,r,a[N],n,m,o;
LL cun,st=1;
bool cmd(LL a,LL b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}o=a[1];
	sort(a+1,a+n*m+1,cmd);
	for(int i=1;i<=n*m;i++){
		if(a[i]==o){
			cun=o;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[st++]==cun){
					cout<<i<<' '<<j;//<<' '<<st-1<<' '<<a[st-1];
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[st++]==cun){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
}

