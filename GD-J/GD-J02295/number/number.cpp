#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out,","w",stdout);
	string in;
	cin>>in;
	int flat[10]={0,0,0,0,0,0,0,0,0,0};
	for(int i=0;i<in.size();i++){
		if(int(in[i])>47&&int(in[i])<58) flat[int(in[i])-48]++;
	}
	string ans={};
	for(int i=9;i>=0;i--){
		if(flat[i]>0){
			for(int j=0;j<flat[i];j++) ans+=char(i+48);
		}
	}
	cout<<ans;
	return 0;
}
