#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[101];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int y=n*m;
	for(int i=1;i<=y;i++){
		cin>>arr[i];
	}
	int x=arr[1];
	sort(arr,arr+y+1,cmp);
	int a=0;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(arr[a]==x){
					cout<<i<<' '<<j;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				else{
					a++;
				}
			}
		}
		else{
			for(int j=1;j<=n;j++){
				if(arr[a]==x){
					cout<<i<<' '<<j;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				else{
					a++;
				}
			}
		}
	}
}
