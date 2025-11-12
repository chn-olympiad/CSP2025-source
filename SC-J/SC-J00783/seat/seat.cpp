#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int x,f;
int R;
bool cmp(int x,int y){
	return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;++i){
    	cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;++j){
		if(j%2==1){
			x=1,f=1;
			for(int i=1;i<=n;++i){
				if(a[(j-1)*n+i]==R){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}else if(j%2==0){
			x=n,f=-1;
			for(int i=n;i>=1;--i){
				if(a[(j-1)*n+(n-i+1)]==R){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
