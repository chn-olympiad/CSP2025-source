#include<bits/stdc++.h>
using namespace std;


const int N=110;
int a[N],b[N][N];

int n,m,x;
bool cmp(int x ,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	int cnt=0;
	sort(a+1,a+1+n*m,cmp);
    for(int j=1;j<=m;j++){
    	if(j%2==1)
    	for(int i=1;i<=n;i++){
    		cnt++;
    		b[i][j]=a[cnt];
    		if(b[i][j]==x){
    			cout<<j<<" "<<i;
    			return 0;
			}
		}
		else{
			for(int i=n;i>=1;i--){
	    		cnt++;
	    		b[i][j]=a[cnt];
	    		if(b[i][j]==x){
	    			cout<<j<<" "<<i;
	    			return 0;
				}
			}
		}
	}
}
