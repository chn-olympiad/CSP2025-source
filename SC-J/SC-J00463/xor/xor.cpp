#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int a,b,flag=0;
int x[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>x[i];
	}
	int l=0,r=0,cnt=0;
	while(l<a){
		for(int i=l;i<=r;i++){
			if(i==l){
				cnt=x[l];
			}else{
				cnt=cnt^x[i];
			}
		}
		if(l==r){
			cnt=x[l];
		} 
		if(cnt==b){
			flag++;
			l=r+1;
			r=l;
		}else{
			r++;
		}
		if(r==a-1){
			l++;
			r=l;
		}
		cnt=0;
	}
	cout<<flag;
	return 0;
}