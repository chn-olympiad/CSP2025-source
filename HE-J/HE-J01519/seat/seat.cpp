#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++){
		cin>>a[i];
	}
	int tmp=a[1];
	sort(a+1,a+len+1,cmp);
	int flag=0;
	for(int i=1;i<=len;i++){
		if(a[i]==tmp){
			flag=i;
		}
	}
	int c=0,r=0;//lie hang
	if(flag%n!=0){
		c=(flag/n)+1;
	}else{
		c=(flag/n);
	}
	r=flag%n;
	if(c%2==1){
		if(r==0){
			cout<<c<<" "<<n;
		}else{
			cout<<c<<" "<<r;
		}
	}else{
		if(r==0){
			cout<<c<<" "<<1;
		}else{
			cout<<c<<" "<<n+1-r;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
