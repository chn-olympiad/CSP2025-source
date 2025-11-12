#include<bits/stdc++.h>
using namespace std;
struct node{
	int d1,d2,d3;
}a[100868];
int n;
int ans[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int z=1;z<=T;z++){
		cin>>n;
		int udi[4]={0,0,0};
		for(int i=1;i<=n;i++){
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
		}
		for(int i=1;i<=n;i++){
			int b[4]={1,2,3},v;
			if(a[i].d1>a[i].d2){
				swap(a[i].d1,a[i].d2);
				swap(b[1],b[2]);
			}
			if(a[i].d2>a[i].d3){
				swap(a[i].d2,a[i].d3);
				swap(b[2],b[3]);
			}
			if(a[i].d1>a[i].d3){
				swap(a[i].d1,a[i].d3);
				swap(b[1],b[3]);
			}
			if(udi[b[1]]<=n/2){
				ans[z]+=a[i].d1;
				udi[b[1]]++; 
			}
			else if(udi[b[2]]<=n/2){
				ans[z]+=a[i].d2;
				udi[b[2]]++;
			}
			else{
				ans[z]+=a[i].d3;
				udi[b[3]]++;
			}
		}
	}
	for(int i=1;i<=T;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
} 
