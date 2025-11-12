#include<bits/stdc++.h>
using namespace std;
int a[200];
int R=0;
int main(){
	memset(a,0,sizeof(a));
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int kuang,lei;
	cin>>kuang>>lei;
	for(int i=0;i<kuang*lei;i++){
		scanf("%d",&a[i]); 
	}
	R=a[0];
	for(int i=0;i<kuang*lei;i++){
		bool flag=false;
		for(int i=0;i<kuang*lei;i++){
			if(a[i]<a[i+1]){
				swap(a[i],a[i+1]);
				flag=true;
			}
		}
		if(!flag){
			break;
		}
	}
	int mid=kuang*lei/2;
	int right=0;
	int left=kuang*lei-1;
	while(a[mid]!=R){
		if(a[mid]>R){
			right=mid;
			mid=(right+left)/2;
		}
		else{
			left=mid;
			mid=(right+left)/2;
		}
	}
	int t=((mid+1)/kuang);
	if(mid+1-t*kuang>0){
		cout<<t+1<<" ";
		t++;
	}else{
		cout<<t<<" ";
	}
	if(t==1){
		cout<<mid+1;
		return 0;
	}
	if(t%2==0){
		cout<<kuang-(mid+1-t*kuang);
	}else{
		cout<<mid+1-t*kuang;
	}
}
