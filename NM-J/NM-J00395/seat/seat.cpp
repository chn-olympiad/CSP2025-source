#include<bits/stdc++.h>
using namespace std;
int n,m,a[10007];
int main(){
    scanf("%d%d",&n,&m);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}int cj=a[1];
	sort(a+1,a+n*m+1);
	int mc=n*m+1;
	for(int i=1;i<=n;i++){
		if(i%2==1) for(int j=1;j<=m;j++){
			if(a[--mc]==cj){cout<<i<<" "<<j<<endl;return 0;}
		}else for(int j=m;j>=1;j--){
			if(a[--mc]==cj){cout<<i<<" "<<j<<endl;return 0;}
		}
	}
    return 0;
}
