#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out";"w",stdout);
	for(int i=0;i<=a[10002];i++){
		cin>>a[i];
		if(a[i]>=0){
			i++;
		}else{
			a[i]=0;
		}
		if(a[i]>a[i+1]){
			a[i]=a[i+2];
		} 
		cout<<a[i];
	}
	return 0;
}
