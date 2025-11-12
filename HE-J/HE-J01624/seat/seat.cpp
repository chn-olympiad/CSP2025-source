#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int a[N],n,m,k;
bool b;
bool cmp(int d,int b){
	return d>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+(n*m),cmp);
	int h=0,l=1;
	for(int i=1;i<=n*m;i++){
		if(b){
			h--;
		}else{
			h++;
		}
		if(h==n+1){
			l++;
			b=1;
			h--;
		}
		if(h==0){
			l++;
			b=0;
			h++;
		}
		if(a[i]==k){
			cout<<l<<' '<<h;
		}
	}
	return 0;
} 
