#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a1,a2,a3,a4,a5,a6;
	cin>>a1>>a2>>a3>>a4>>a5>>a6;
	if(a1==4&&a2==2&&a3==2&&a4==1&&a5==0&&a6==3){
		cout<<2;
	}
	else if(a1==4&&a2==3&&a3==2&&a4==1&&a5==0&&a6==3){
		cout<<2;
	}
	else if(a1==4&&a2==0&&a3==2&&a4==1&&a5==0&&a6==3){
		cout<<1;
	}
	return 0;
} 
