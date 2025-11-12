#include<bits/stdc++.h>
using namespace std;
int arr[110];
int num=1;
bool cmp(int a,int b){
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>arr[i];
	}
	int sum=arr[1];
	sort(arr+1,arr+1+(n*m),cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(arr[num]==sum){
					cout<<i<<" "<<j;
					return 0;
				}
				num++;
			}
		}else{
			for(int x=m;x>=1;x--){
				if(arr[num]==sum){
					cout<<i<<" "<<x;
					return 0;
				}
				num++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
