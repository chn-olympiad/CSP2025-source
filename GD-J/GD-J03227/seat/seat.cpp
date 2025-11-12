#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int R;
int cnt;
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			cnt=i;
			break;
		}
	}
	if(cnt%n!=0) cout<<cnt/n+1<<" ";
	else{//能整除,要么在第一行要么在最后一行 
		int k=cnt/n;
		if(k%n==0){//偶数列 
			cout<<cnt/n<<" "<<1;
		}
		else cout<<cnt/n<<" "<<n;
		return 0; 
	}
	int k=cnt%n;
	if(((cnt/n)+1)%2==0){//偶数列 
		cout<<n-k+1;
	}
	else cout<<k;
	return 0;
 } 
