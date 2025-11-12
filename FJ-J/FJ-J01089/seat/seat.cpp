#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int id;
	int so;
};
node a[1005]={};
int nm;
bool cmp(node a,node b){
	return a.so>b.so;
}
int h=1,l=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>a[i].so;
		a[i].id=i;
	}
	sort(a+1,a+nm+1,cmp);
	for(int i=1;i<=nm;i++){
		if(a[i].id==1){
			cout<<l<<" "<<h;
			return 0;
		}
		if(l%2==1){
			h++;
			if(h>n){
				h=n;
				l++;
			}
		}else{
			h--;
			if(h<1){
				h=1;
				l++;
			}
		}
	}
	return 0;
}
