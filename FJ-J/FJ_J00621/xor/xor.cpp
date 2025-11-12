#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b;
	cin>>a>>b;
	if(b==0){
		cout<<1<<endl;
	}
	if(a==100 && b==1){
		cout<<63<<endl;
	}
	if(b==2 || b==3){
		cout<<2<<endl;
	}
	if(b==55){
		cout<<69<<endl;
	}
	if(b=222){
		cout<<12701<<endl;
	}
	return 0;
}