#include<bits/stdc++.h>
using namespace std;
struct cl{
	int x,a,b,c;
	int aid,bid,cid;
};
cl arr[100005];
int n,m;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m;
		int dlen=m/2,ans=0;
		int len[5]={};
		int ar[3][100000]={};
		for(int j=0;j<m;j++){
			cin>>arr[j].a>>arr[j].b>>arr[j].c;
			arr[j].aid=1,arr[j].bid=2,arr[j].cid=3;
			if(arr[j].a<arr[j].b)swap(arr[j].a,arr[j].b),swap(arr[j].aid,arr[j].bid);
			if(arr[j].b<arr[j].c)swap(arr[j].b,arr[j].c),swap(arr[j].bid,arr[j].cid);
			if(arr[j].a<arr[j].b)swap(arr[j].a,arr[j].b),swap(arr[j].aid,arr[j].bid);
			arr[j].x=arr[j].a-arr[j].b;
			if(len[arr[j].aid]<dlen){
				ans+=arr[j].a;
				int tmp=++len[arr[j].aid];
				ar[arr[j].aid][tmp]=arr[j].x;
				while(ar[arr[j].aid][tmp]<ar[arr[j].aid][tmp-1]&&tmp>1){
					swap(ar[arr[j].aid][tmp],ar[arr[j].aid][tmp--]);
				}
				tmp=len[arr[j].aid];
			}
			else if(arr[j].b<arr[j].a-ar[arr[j].aid][1]){
				ans=ans+arr[j].a-ar[arr[j].aid][1];
				ar[arr[j].aid][1]=arr[j].x;
				int tmp=1;
				while(ar[arr[j].aid][tmp]>ar[arr[j].aid][tmp+1]){
					swap(ar[arr[j].aid][tmp],ar[arr[j].aid][tmp++]);
				}
			}
			else {
				ans+=arr[j].b;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
