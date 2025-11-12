#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ji=0;
	cin>>n>>m;
	int a[n][m]={0},b[n*m+5]={0},c[n*m+5]={0};
	for(int i=1;i<=n*m;i++) cin>>b[i];
	int r=b[1];
	int xiao=b[1],da=b[1];
    for(int i=1;i<=n*m;i++){
		c[b[i]]++;
		xiao=min(b[i],xiao);
		da=max(b[i],da);
	}
	for(int k=1,i=da;i>=xiao;i--){
		while(c[i]){
			b[k]=i;
			k++;
			c[i]--;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
			    ji++;
			    a[j][i]=b[ji];
			    if(r==a[j][i]){
				    cout<<i<<" "<<j;
				    return 0;
			    }
		    }
		}
		else{
			for(int j=n;j>=1;j--){
				ji++;
				a[j][i]=b[ji];
				if(r==a[j][i]){
				    cout<<j<<" "<<i;
				    return 0;
			    }
			}
		}
	}

	return 0;
}
