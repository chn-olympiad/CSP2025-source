#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
int arr[N];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,num;
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>arr[i];
	}
	num=arr[1];
	sort(arr+1,arr+1+n*m,greater<int>());
	int i=0,j=1,k=0,x=1;
	while(arr[k]!=num){
		i+=x;
		k++;
		if(i>n){
			i=n;
			j++;
			x*=-1;
		}else if(i<1){
			i=1;
			j++;
			x*=-1;
		}
	}
	cout<<j<<" "<<i;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
