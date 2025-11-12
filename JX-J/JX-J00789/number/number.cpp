#include<bits/stdc++.h>
using namespace std;
string x;
int s; 
int a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>x;
    int z=x.size();
    for(int i=0;i<z;i++){
		if(x[i]>='0'&&x[i]<='9'){
			 a[i]=x[i]-48;
			 if(x[i]=='0') s++;
		}
	}
	sort(a,a+z-1);
	for(int i=z-1;i>=0;i--){
		if(a[i]>0) cout<<a[i];
	}
	for(int i=0;i<s;i++) cout<<0;
	return 0;
}
