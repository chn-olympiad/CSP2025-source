#include<bits/stdc++.h>
using namespace std;
int a[110],b[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int s[15][15];
    int n,m,d,q=1;
    cin>>n>>m;
    int r=m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    int g=a[1];
	sort(b+1,b+n*m+1);
	for(int i=1;i<=n*m;i++){
		a[i]=b[n*m-i+1];
	}
    int x=1;
    for(int j=1;j<=n;j++){
    	if(j%2==0){
    		d=-1;
    		r=1;
    		q=n;
    		for(q=q;q>=r;q=q+d){
            s[q][j]=a[x];
            x++;
			}
		}else{
			d=1;
			r=m;
			q=1;
			for(q=q;q<=r;q=q+d){
            s[q][j]=a[x];
            x++;
        	}
		}
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]==g){
                n=j;
				m=i;
            }
        }

    }
    cout<<n<<m;
    return 0;
}
