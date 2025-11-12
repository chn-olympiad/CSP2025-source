#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string sh;
	int a[100]={0};
	cin>>sh;
	for(int i=0;i<sh.size();i++){
		if(sh[i]>='0'&&sh[i]<='9')a[int(sh[i]-'0')]++;
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=0;j<a[i];j++)cout<<i;
		}
	}
}  
