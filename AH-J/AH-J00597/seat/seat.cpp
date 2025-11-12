#include<bits/stdc++.h>
using namespace std;
int zuowei[11][11]={},n,m,a[105]={},cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int b=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>0;i--){
		if(a[i]==b){
			if(cnt%n!=0){
				if((cnt/n+1)%2==1)cout<<cnt/n+1<<" "<<cnt%n;
				else cout<<cnt/n+1<<" "<<n-(cnt%n)+1;
			}else{
				if(cnt/n%2==1)cout<<cnt/n<<" "<<n;
				else cout<<cnt/n<<" "<<1;
			}
			return 0;
		}
		cnt++;
	}
	return 0;
}
