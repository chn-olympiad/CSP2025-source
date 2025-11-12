#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int n,m;
int q[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>q[i]>>q[j];
			if(q[i]+q[j]>n*m){
			    break;
			}else 
            if(q[i]>q[j]&&q[i-1]>q[i]){
				cout<<n-1<<m-1;
			}else if(q[i]>q[j]&&q[i]>q[i+1]){
				cout<<n-1<<m;
			}else if(q[i]>q[j]&&q[j-1]>q[j]){
				cout<<n<<m;
			}else if(q[i]>q[j]&&q[j+1]>q[j]){
				cout<<n-1<<m;
			}
		}
	}
	cout<<n<<" "<<m;
	return 0;
}











//freopen("number.in","r",stdin);
//freopen("number.out","w",stdout);
