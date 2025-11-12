#include<bits/stdc++.h>

using namespace std;
int b[102]; 
int nr,mr,n,m,R,sum,minn=1;

int main(){
	freopen("seat1.in","r",stdin);
	freopen("seat1.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>b[i];
	}R=b[1];
	for(int i=2;i<=sum;i++){
		if(b[i]>R){
			minn++;
		}
	}
	if(minn%n==0){
		mr=minn/n;
		if(mr%2==1){
			nr=n;
		}else{
			nr=1;
		}
	}else{
		mr=(minn/n)+1;
		if(mr%2==1){
			nr=minn%n;
		}else{
			nr=n-(minn%n);
		}
	}cout<<mr<<" "<<nr;
	return 0;
} 