#include<bits/stdc++.h>
using namespace std;
const int Max = 5e5+1;
int n,k,result;
int arr[Max];

int counting(int start,int value){
	int rs = 0;
	int leave = value;
	for(int j=start;j<n;++j){
		leave^=arr[j];
		if(leave==0){
			return 1;
		}
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;++i){
		scanf("%d",arr+i);
		arr[i] ^= k;
	}//从arr中尽可能多的选择不相交的段使得异或结果为0
	for(int i=0;i<n;++i){
		result+=counting(i+1,arr[i]);
	}printf("%d",result);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
