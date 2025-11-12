#include <bits/stdc++.h>
using namespace std;
int n,m,a[10001],b[1001][1001],grade,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
         cin>>a[i];
	}
	cnt=n*m;
	grade=a[1];
	sort(a+1,a+1+n*m);

	for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                b[i][j]=a[cnt];
                cnt--;
            }
        }else{
            for(int j=n;j>=1;j--){
                b[i][j]=a[cnt];
                cnt--;
            }

        }
	}
	for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]==grade){
                cout<<i<<" "<<j;
                return 0;
            }
        }
	}


	return 0;
}
