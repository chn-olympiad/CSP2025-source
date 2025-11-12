#include<bits/stdc++.h>
using namespace std;
int p[1000000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>p[i];
	}
	sort(p+1,p+a+1,cmp);
	if(b==0){
		cout<<1;
	}else{
		cout<<p[2];
	}
	return 0;
}
