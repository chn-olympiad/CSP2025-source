#include<bits/stdc++.h>
using namespace std;
int n,m,n1=1,m1=1;
int a[105],a1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	a1=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>0;i--){
		if(n1%2==1){
			if(a[i]!=a1){
				if(m1>=m){
					n1++;
				}else{
				m1++;	
				}
			}else{
				break;
			}
		}else{
			if(a[i]!=a1){
				if(m1<=1){
					n1++;
				}else{
				m1--;	
				}
			}else{
				break;
			}
		}
	}
	cout<<n1<<' '<<m1;
	return 0;
}

