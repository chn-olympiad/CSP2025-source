#include<bits/stdc++.h>
using namespace std;
bool comp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char op[100005];
	cin>>op+1;
	int ai[10005];
	int n=strlen(op+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		//if(op[i]<='z'||op[i]>='a')op[i]='A';
		 if(op[i]<='9'&&op[i]>='0'){
			ai[i]=op[i]-48;
			ans++;
			//cout<<ai[i]<<" ";
		}
	}
	sort(ai+1,ai+1+n,comp);
	for(int i=1;i<=ans;i++){
		cout<<ai[i];
	}
	return 0;
}

