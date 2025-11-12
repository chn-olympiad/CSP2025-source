#include<bits/stdc++.h>
using namespace std;
int n,m,r,a[110],p[10010][2];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
        cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+(n*m)+1);
	bool mod=0;
	p[1][0]=1;p[1][1]=1;
	for(int i=2;i<=n*m;i++){
        if(mod==0){
            if(p[i-1][1]!=n){
				p[i][0]=p[i-1][0];
				p[i][1]=p[i-1][1]+1;
			}
			else{
				p[i][0]=p[i-1][0]+1;
				p[i][1]=p[i-1][1];
				mod=1;
			}
        }
		else{
			if(p[i-1][1]!=1){
				p[i][0]=p[i-1][0];
				p[i][1]=p[i-1][1]-1;
			}
			else{
				p[i][0]=p[i-1][0]+1;
				p[i][1]=p[i-1][1];
				mod=0;
			}
		}
	}
	int k=1;
	for(int i=n*m;i>=1;i--){
		if(a[i]==r){
			cout<<p[k][0]<<" "<<p[k][1];
			return 0;
		}
		else k++;
	}
	for(int i=n*m;i>=1;i--) cout<<a[i];
	return 0;
}
