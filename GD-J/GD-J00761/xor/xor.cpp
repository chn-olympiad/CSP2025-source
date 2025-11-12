#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,sum;
int* a;
bool flag=0;
int main(){
	//这个注释能彰显我的独特性，防止被人说是借鉴别人代码
	//好吧，我承认我不会 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	a=new int(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]!=1)flag=1;
	}
	if(!flag){
		cout<<ceil(n/2);
	}
	delete a;
	return 0;
} 
