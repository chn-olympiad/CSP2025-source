#include<bits/stdc++.h>
using namespace std;
int a[15][15],n,m,b[105],ans,tot;
bool cmp(int c,int d){
	return c>d;
} 
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
        if(i==1)ans=b[i];
    }
    sort(b+1,b+n*m+1,cmp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
			    tot++;
                if(i%2!=0){
			       a[i][j]=b[tot];	 
			    }
			    else if(i%2==0){
				    a[i][m-j+1]=b[tot]; 
			    }
		    }
        }
    for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans==a[i][j])cout<<i<<" "<<j;
		}
		cout<<endl;
	}
	return 0;
}
