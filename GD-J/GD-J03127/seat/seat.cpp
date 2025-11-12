#include<bits/stdc++.h>
using namespace std;
const int ri=105;
int n,m,a[ri],tot,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[++tot]);
			if(a[tot]>=a[1]) cnt++;
		}
	}
	int x=cnt/n+(cnt%n!=0);
	cout<<x<<" ";
	if(x%2==1){
		cout<<cnt-n*(x-1)<<endl;
	}else{
		cout<<n-(cnt-n*(x-1))+1<<endl;
	}
	return 0;
} //风堇老婆等我回家 
