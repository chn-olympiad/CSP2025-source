#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int len=n*m;
	int c;
	cin>>c;
	int arr[len];
	arr[0]=c;
	for(int i=1;i<len;i++){
		cin>>arr[i];
	}
	int ans[len];
	int k=0,max=0,l=0;
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			if(arr[j]>max){
				max=arr[j];
				l=j;
			}
		}
		ans[k]=max;
		k++;
		arr[l]=0;
		max=0;
	}
	int index=0;
	for(int i=0;i<len;i++){
		if(ans[i]==c) index=i+1;
	}
	int rn,rm;
	rm=(index+n-1)/n;
	if(rm%2==1){
		rn=index%n;
	}else{
		rn=n-(index%n);
	}
	cout<<rm<<' '<<rn;
	return 0;
}
