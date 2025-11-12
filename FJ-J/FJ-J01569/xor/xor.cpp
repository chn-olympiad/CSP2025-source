#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=2e5+5;
int a[N];

bool check1(int l,int r){
	
	bool f;
	if(a[l]==1) f=true;
	else f=false;
	
	for(int i=l+1;i<=r;i++){
		if((a[i]==1&&f==true)||(a[i]==0&&f==false)) f=false;
		else if((a[i]==1&&f==false)||(a[i]==0&&f==true)) f=true;
	}
    return f;
}
bool check2(int l,int r){
	
	bool f=a[l];
	for(int i=l+1;i<=r;i++){
		if((a[i]==1&&f==true)||(a[i]==0&&f==false)) f=false;
		else if((a[i]==1&&f==false)||(a[i]==0&&f==true)) f=true;
	}
	return !f;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(k>=2){
		cout<<0;
		return 0;
	}
	
	int l=1,r=1;
	
	int sum=0;
	while(l<=n){
		if(r>n){
			l++;
			r=l;
		}
		
		if(k==1&&check1(l,r)) {
			l=r+1;
			r=l;
			sum++;
			continue;
		}
		else if(k==0&&check2(l,r)) {
			sum++;
			l=r+1;
			r=l;
			sum++;
			continue;
		}
		r++;
	}
	cout<<sum;
	return 0;
}

