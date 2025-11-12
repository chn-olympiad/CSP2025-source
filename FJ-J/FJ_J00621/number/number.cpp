#include<bits/stdc++.h>
using namespace std;
int m[20],x=0;
int slen(string q){
	int i=0;
	while(q[i]){
		i++;
	}
	return i;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int cd,ans;
	cin>>a;
	cd=slen(a);
	for(int i=0;i<cd;i++){
		if(a[i]>='0' && a[i]<='9'){
			m[a[i]-48]+=1;
			x++;
		}
	}
	for(int i=0;i<m[9];i++){
		cout<<9;
	}
	for(int i=0;i<m[8];i++){
		cout<<8;
	}
	for(int i=0;i<m[7];i++){
		cout<<7;
	}
	for(int i=0;i<m[6];i++){
		cout<<6;
	}
	for(int i=0;i<m[5];i++){
		cout<<5;
	}
	for(int i=0;i<m[4];i++){
		cout<<4;
	}
	for(int i=0;i<m[3];i++){
		cout<<3;
	}
	for(int i=0;i<m[2];i++){
		cout<<2;
	}
	for(int i=0;i<m[1];i++){
		cout<<1;
	}
	for(int i=0;i<m[0];i++){
		cout<<0;
	}
	cout<<endl;
	return 0;
}