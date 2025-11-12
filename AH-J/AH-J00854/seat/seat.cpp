#include<bits/stdc++.h>
using namespace std;
int arr[110],n,m,a1;
bool inline cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a1;
	arr[0]=a1;
	for(int i=1;i<n*m;i++)cin>>arr[i];
	sort(arr,arr+n*m,cmp);
	int x=1,y=1;
	for(int i=0;;i++){
		if(arr[i]==a1){
			cout<<x<<' '<<y;
			break;
		}else{
			if(x&1){
				if(y==n)x++;
				else y++;
			}else{
				if(y==1)x++;
				else y--;
			}
		}
	}
	return 0;
}
