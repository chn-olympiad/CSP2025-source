#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a1,b;
	cin>>a1>>b;
	for(int i=0;i<a1;i++){
		cin>>a[i];
	}
	int n=0;
	if(b==0){
		for(int i=0;i<a1;i++){
			if(a[i]==0){
				b++;
			}
			else if(a[i]==1&&a[i+1]==1){
				b++;
				i++;
			}
		}
	}
	else if(b==1){
		for(int i=0;i<a1-1;i++){
			if(a[i]==1){
				b++;
			}
		}
	}
	cout<<b;
	return 0;
}
