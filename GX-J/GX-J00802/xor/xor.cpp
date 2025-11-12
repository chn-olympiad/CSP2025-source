#include <stdio.h>
#include <iostream>
using namespace std;
int n,k;
int arr[500005];
int cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	int st=0;
	int yhh=arr[0];
	for(int i=0;i<n;i++){
		/*if(arr[i]==k){
			cnt++;st=i+1;yhh=arr[st];
			continue;
		}*/
		if(i!=st)yhh=yhh^arr[i];
		//cout<<'&'<<i<<' '<<yhh<<' '<<arr[i]<<endl;
		if(yhh==k){
			//cout<<st<<' '<<i<<' '<<endl;
			cnt++;
			yhh=arr[i+1];st=i+1;
		}
		else if(i==n-1){
			i=st;st=i+1;
		}
	}
	printf("%d",cnt);
	return 0;
}
//freopen("xor.in","r",stdin);
//freopen("xor.out","w",stdout);
// Idk how to solve this problem :<
// However I Love Nahida Forever!!!

