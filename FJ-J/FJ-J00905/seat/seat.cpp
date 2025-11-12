#include<bits/stdc++.h>
using namespace std;
long long n,m,num;
long long czx[10005];
long long a[105][105];
int main ()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n*m;i++){
		cin>>czx[i];
	}
	num=czx[1];
	sort(czx+1,czx+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(num==czx[i]){
			int hh=n*m-i+1;
			int ddd=0;//µÚ¼¸ÁÐ 
			if(hh%n==0){
				cout<<hh/n<<" ";
				ddd=hh/n;
			}else{
				cout<<hh/n+1<<" ";
				ddd=hh/n+1;
			}
			if(ddd%2==1){
				cout<<hh%n;
			}else{
				cout<<n-hh%(n+1);
			}
			break;
		}
	}
	return 0;
 } 
