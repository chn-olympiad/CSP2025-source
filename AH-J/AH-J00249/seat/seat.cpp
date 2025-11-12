#include<bits/stdc++.h>
using namespace std;
int n,m,a[11000],b[110][110],l;

bool cmp(int x,int y){
	return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    l=n*m;
    for(int i=1;i<=l;i++){
		cin>>a[i];
    }
    int g=a[1];
    sort(a+1,a+l+1,cmp);
    int k=1;
    for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				b[j][i]=a[k];
				k++;
			}
		}
		else{
			for(int j=1;j<=n;j++){
				b[j][i]=a[k];
				k++;
			}
		}
    }
    for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==g){
				cout<<j<<" "<<i<<endl;
				return 0;
			}
		}
    }
	return 0;
}
