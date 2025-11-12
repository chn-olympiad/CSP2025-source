#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+9;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,num;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			num=a[i];
		}
	}
	
	int cnt;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			cnt=i;
			break;
		}
	}
	
	if(cnt%n==0){
		cout<<cnt/n<<" ";
		if((cnt/n)%2!=0){
			cout<<n;
		} 
		else{
			cout<<"1"; 
		}
	}
	else{
		cout<<cnt/n+1<<" ";
		if((cnt/n+1)%2!=0){
			cout<<cnt%n;
		} 
		else{
			cout<<n-cnt%n+1; 
		}
	}
	return 0;
}
