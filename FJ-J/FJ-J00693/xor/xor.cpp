#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
bool f(int x,int y){
	if(x==y){
		if(a[x]==k){
			return 1;
		}
	}
	int dd=a[x];
	for(int i=x+1;i<=y;i++){
		dd=dd^a[i];
	}
	if(dd==k){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int num=0;
	int l,r;
	l=1;
	while(l<n){
		for(r=l;r<=n;r++){
			if(f(l,r)==1){
		    	l=r;
		    	num++;
		    	break;
		    }
		}
		l++;
	}	
	cout<<num;
	fclose(stdin);
	fclose(stdout);
}
