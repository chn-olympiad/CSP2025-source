#include <bits/stdc++.h>
using namespace std;
int a[500010];
int n,k;
int c;
void s1(){
	if(a[1]==0&&a[2]==0) c=2;
	else if(a[1]==0) c=1;
	else if(a[2]==0) c=1;
	else if(a[1]==a[2]) c=1;
	else c=0;
	cout<<c;
}
void s2(){
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			c++;
		}
	}
	for(int i=2;i<=n;i++){
		if(abs(a[i-1]-a[i])==1&&a[i]!=1&&a[i-1]!=1){
			c++;
			a[i]=1;
			a[i-1]=1;
		}
	}
	cout<<c;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0&&n<=2) s1();
	else if (k==1) s2();
	return 0;
} 

