#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m;
int a[1000];
bool cmp(int p,int q){
	return p>q;
}
bool check(int c){
	if(c>=m){
		if(c%n==0){
			if((c/n)%2==1){
				return true;
			}else if((c/n)%2==0){
				return false;
			}
		}else if(c%n!=0){
			if((c/n+1)%2==1){
				return true;
			}else if((c/n+1)%2==0){
				return false;
			}
		}
	}else{
		return true;
	}
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int w=n*m;
	for(int i=1;i<=w;i++){
		cin>>a[i];
	}
	int r=a[1];
	int x;
	sort(a+1,a+w+1,cmp);
	for(int i=1;i<=w;i++){
		if(a[i]==r){
			x=i;
			break;
		}
	}
	int h,l;
	if(check(x)==true){
		if(x<=m){
			h=1;
			l=x;
		}else{
			if(x%m==0){
				h=x/m;
			}else{
				h=x/m+1;
			}
			l=x%m;
		}
	}else if(check(x)==false){
		if(x%m==0){
			h=x/m;
		}else{
			h=x/m+1;
		}
		if(x%m==0){
			l=1;
		}else{
			l=m-(x%m)+1;
		}
	}
	cout<<h<<" "<<l<<endl;
	return 0;
}
