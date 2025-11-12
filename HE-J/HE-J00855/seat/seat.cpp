#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long space=n*m;
	int arr[n*m];
	int x=1,y=1;
	bool p=true;
	for(int i=0;i<n*m;i++){
		cin>>arr[i];
	}
	int xy_R=arr[0];
	for(int i=0;i<n*m;i++){
		for(int j=i;j<n*m-1;j++){
			if(arr[i]<arr[j]){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
				break;
			}
		}
	}
	int t=0;
	while(t!=space){
		if(arr[t]==xy_R){
			cout<<y<<" "<<x;
			break;
		}else if(arr[t]!=xy_R&&x!=m&&p&&y!=n){
			x++;
			t++; 
		}else if(arr[t]!=xy_R&&x==m&&y!=n){
			y++;
			p=false;
			t++;
		}else if(arr[t]!=xy_R&&x!=m&&y!=n&&!p){
			x--;
			t++;
		}else if(arr[t]!=xy_R&&x==1&&y!=n){
			y++;
			t++;
			p=true;
		}else if(arr[t]!=xy_R&&x==m&&y==n&&x%2!=0&&y%2!=0){
			x--;
			p=false;
			t++;
		}else if(arr[t]!=xy_R&&y==n&&x!=m&&!p){
			x--;
			t++;
		}
	}
	return 0;
}
