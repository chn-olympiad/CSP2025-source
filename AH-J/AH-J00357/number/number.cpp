#include<bits/stdc++.h>
using namespace std;
char a[1000010];
int c[10];
int x[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int t=0;
	for(int i=0;i<1000010;i++){
		int s=a[i];
		if(s>=49&&s<=57){
			x[s-48]=1;
			c[s-48]=c[s-48]*10+s-48;
		}
		if(s==48){
			t++;
		}
	}
	for(int i=9;i>0;i--){
		if(x[i]==1){
			cout<<c[i];
		}
	}
	for(int i=t;i>0;i--){
		cout<<0;
	}
	return 0;
}
