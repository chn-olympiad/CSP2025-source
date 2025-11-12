#include<bits/stdc++.h>
using namespace std;
string h;
const char N='0';
int s=0,a[1000000];
bool flag=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>h;
	for(int i=0;i<h.size();i++){
		if(h[i]-N>=0 and h[i]-N<=9){
			a[s]=h[i]-N;
			s++;
		}
	}
	sort(a,a+s);
	for(int i=s-1;i>=0;i--){
		if(flag){
			if(a[i]!=0){
				flag=0;
				cout<<a[i];
			}else{
				//
			}
		}else{
			cout<<a[i];
		}
	}
	if(flag){
		cout<<0; 
	}
	return 0;
} 