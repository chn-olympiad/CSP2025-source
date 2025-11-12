#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p[110],p1;
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++){
		cin>>p[i];
		if(i==1)p1=p[i];
	}
	sort(p+1,p+len+1,cmp);
	int l;
	for(int i=1;i<=len;i++){
		if(p[i]==p1){
			l=i;
			break;
		}
	}
	int c=1,r=1;
	bool f=true;
	for(int i=1;i<=l-1;i++){
		if(f){
			if(r>=n){
				c++;
				f=false;
			}
			else r++;
		}
		else{
			if(r<=1){
				c++;
				f=true;
			}
			else r--;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
