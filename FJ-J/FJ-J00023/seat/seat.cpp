#include<bits/stdc++.h>
using namespace std;
#define long long int
int arr[15]; 
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x;
	cin>>x;
	arr[1] = x;
	for(int i = 2;i<=n*m;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n*m,cmp);
	int cnt = 0;
	for(int i = 1;i<=n*m;i++){
		if(arr[i]==x){
			cnt = i;
			break;
		}
	}
	if(cnt%m==0){
		cout<<cnt/n<<" ";
	}else{
		cout<<cnt/n+1<<" ";
	}
	cnt = cnt%(2*n);
	if(cnt<=n){
		cout<<cnt;
	}else{
		cnt = cnt%n;
		int c = 0;
		for(int i = n;i>=1;i--){
			c++;
			if(c==cnt){
				cout<<i;
				break;
			}
		}
	}
	return 0;
}
