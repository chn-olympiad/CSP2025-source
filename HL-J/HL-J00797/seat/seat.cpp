#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m;
int a[N],b[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s=0;
	while(cin>>a[s]){
		s++;
	}
	int maxn=-1,myi=-1;
	for(int j=0;j<s;j++){
		for(int i=0;i<s;i++){
			if(a[i]>maxn){
				maxn=a[i];
				myi=i;
			}
		}
		b[j]=maxn;
		a[myi]=-1;
		maxn=-1;
		myi=-1;
	}
	int R=0;
	for(int i=0;i<s;i++){
		if(b[i]==a[1]){
			R=i;
		}
	}
	
	int l=0,h=0,x=0;
	if(R%n==0){
		l=R/n;
		x=R%n;
		if(x%2==0){
			h=1;
		}else{
			h=n;
		}
	}else{
		x=R/n;
		if(x%2==0){
			h=1;
		}else{
			h=n;
		}
		l=R/n+1;
	}
	cout<<l<<" "<<h;
	return 0;
}
