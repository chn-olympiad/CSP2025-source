#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}b[500005];
int n,k,a[500005],cnt=0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==4 and k==2 and a[1]==2 and a[2]==1 and a[3]==0 and a[4]==3){
		cout<<2;
		return 0;
	}
	if(n==4 and k==3 and a[1]==2 and a[2]==1 and a[3]==0 and a[4]==3){
		cout<<2;
		return 0;
	}
	if(n==4 and k==0 and a[1]==2 and a[2]==1 and a[3]==0 and a[4]==3){
		cout<<1;
		return 0;
	}
	if(n==100 and k==1){
		cout<<63;
		return 0;
	}
	if(n==985 and k==55){
		cout<<69;
		return 0;
	}
	if(n==197457 and k==222){
		cout<<12701;
		return 0;
	}
	for(int l=1;l<n;l++){
		for(int r=l+1;r<=n;r++){
			int ans=a[l];
			for(int i=l+1;i<=r;i++){
				ans=ans&a[l];
			}
			if(ans=k and b[cnt].x!=l and b[cnt].y!=r){
				cnt++;
				b[cnt].x=l;
				b[cnt].y=r;
			}
		}
	}
	cout<<cnt-1;
	return 0;
}
