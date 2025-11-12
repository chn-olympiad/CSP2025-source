#include<bits/stdc++.h>
using namespace std;
long long int n,len;
char a[1000000];
int arr[1000000];
int cmp(int x,int y){
	if(x<=57||y<=57){
		if(x<=57&&y<=57){	
			return x>y;
		}
		else{
			if(x>57){
				return x<y;
			}
			else{
				return y>x;
			}
		}
	}
	else{
		return x<y;
	}
}
int main(){
	freopen("number.in","r",stdisn);
	freopen("number.out","w",stdout);
	cin>>a;
	len=strlen(a);
	for(int i=0;i<len;i++){
		arr[i]=a[i];
	}
	sort(arr,arr+len,cmp);
	for(int i=0;i<len;i++){
		if(arr[i]<=57){
			cout<<arr[i]-48;
		}
	}
	return 0;
}
