#include<bits/stdc++.h>
using namespace std;
int seat[105][105];
int a[10000];
bool cmp(int a,int b){
	return a>b;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cj;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cj=a[1];
	sort(a+1,a+n*m+1,cmp);
	int f=1;
	int h=1,l=1;
	for(int i=1;i<=n*m;i++){
		seat[h][l]=a[i];
		if(a[i]==cj){
			cout<<l<<" "<<h;
			return 0;
		}
		if(f==1){
			h++;
			if(h==n+1){
				h=n;
				l++;
				f=0;
			}
		}
		else{
			h--;
			if(h==0){
				h=1;
				l++;
				f=1;
			}
		}
	}
	return 0;
}
