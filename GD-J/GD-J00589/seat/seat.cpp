#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(const int &a,const int &b){
	return a>b;
}
int main(){
	freopen("seat3.in","r",stdin);
	freopen("seat3.out","w",stdout);
	cin>>n>>m;
	int sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	int r=a[1];
	int pos;
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++){
		if(a[i]==r) pos=i;
	}
	if((int)ceil(pos*1.0/m)%2==1){
		cout<<ceil(pos*1.0/m)<<" ";
		if(pos%m==0) cout<<m;
		else cout<<pos%m;
	}
	else{
		cout<<ceil(pos*1.0/m)<<" ";
		if(pos%m==0) cout<<1;
		else cout<<m-pos%m+1;
	}
	return 0;
	}

