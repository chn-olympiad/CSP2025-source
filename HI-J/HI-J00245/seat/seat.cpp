#include<bits/stdc++.h>
using namespace std;
int arr[1000001],seat[1001][1001];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>arr[i];
	}
	int score=arr[1];
	sort(arr+1,arr+sum+1,cmp);
	int x=1,y=1;
	bool flag=1;
	for(int i=1;i<=sum;i++){
		seat[1][1]=arr[1];
		if(arr[i]==score){
			cout<<x<<' '<<y;
			break;
		}
		if(y==n&&x<=m&&flag==1){
			x++;
			flag=0;
		}
		else if(y==1&&x!=1&&x<=m&&flag==0){
			x++;
			flag=1;
		}
		else if(y<n&&y>=1&&flag==1){
			y++;
		}else if(y<=n&&y>=1&&flag==0){
			y--;
		}
		seat[x][y]=arr[i];
		
	}
	return 0;
}
