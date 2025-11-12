#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int arr[105];
	for(int i=1;i<=n*m;i++){
		cin>>arr[i];
	}
	int a=arr[1];
	int f;
	sort(arr+1,arr+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a==arr[i]){
			f=i;
		}
	}
	int cnt=0;
	if(n==1){
		cout<<f<<" "<<1;
		return 0; 
	}
	if(m==1){
		cout<<1<<" "<<f;
		return 0; 
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=m;i++){
			cnt++;
			if(cnt==f){
				if(j%2==0){
					cout<<j<<" "<<m-i+1;
				}else{
					cout<<j<<" "<<i;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
