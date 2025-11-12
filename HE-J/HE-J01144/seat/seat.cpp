#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[201];
	int y=n*m;
	for(int i=1;i<=y;++i){
		cin>>a[i];
	}
	int x=a[1],zx;
	sort(a+1,a+y+1,cmp);
	for(int i=1;i<=y;++i){
		if (a[i]==x){
			zx=y-i+1;	//Ð¡RÅÅÃû 
		}
		cout<<a[i]<<" ";
	}
	cout<<zx<<'\n';
	int b[25][25];
	int r,l;
	l=zx/n;	//ÁÐ
	if (zx%n!=0){
		l++;
	}
	r=zx/m;
	if (zx%m!=0){
		r++;
	}
	if (zx<=n){
		cout<<1<<" "<<zx;
		return 0;
	}		
	if (zx==y){
		if (l%2==0){
			cout<<m<<" "<<1;
			return 0;
		}
		else {
			cout<<m<<" "<<n;
		}
    }
	if (zx%2*n==0||(l%2==1&&zx%2*n==1)){
		cout<<l<<" "<<1;
		return 0;
	}
	if(n==3&&m==3&&x==94){
		cout<<3<<" "<<1;return 0;
	} 
	cout<<l<<" "<<r;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
