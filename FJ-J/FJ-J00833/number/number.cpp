#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","W",stdout);
	string q;
	char m[10]={};
	int x=0;
	cin>>q;
	for(int i=0;i<q.size();i++){
		if(q[i]>='0'&&q[i]<='9'){
			m[i]=q[i];
		}
	}
	for(int i=0;i<=9;i++){
		for(int j=i+1;j<=9;j++){
			if(m[i]<m[j]){
				swap(m[i],m[j]);
			}
		}
	}
	for(int i=0;i<q.size();i++){
		cout<<m[i];
	}
	return 0;
}
