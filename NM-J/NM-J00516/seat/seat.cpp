#include<bits/stdc++.h>
using namespace std;
int n, m, a[200], f, cnt, c;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    if(n==1&&m==1){
    	cout<<n<<" "<<m;
	}
    cin>>f;
    a[1]=f;
    for(int i=2;i<=n*m;i++){
    	cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==f){
			cnt=i;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;++j){
				c++;
				if(c==cnt){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;--j){
				c++;
				if(c==cnt){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
}
