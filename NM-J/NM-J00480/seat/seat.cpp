#include<bits/stdc++.h>
using namespace std;
int a[10010];
bool cmp(int a,int b){
	if(a>b){
		return true;
	}else{
		return false;
	}
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
long long n=0,m=0,l=0,h=0,c=0,w=0;
long long b=0;
cin>>n>>m;
for(int i=1;i<=n*m;i++){
	cin>>a[i];
}
c=a[1];
sort(a+1,a+1+n*m,cmp);
for(int i=1;i<=n*m;i++){
	if(a[i]==c){
	w=i;
	break;	
	}

}
if(w%n==0){
	l=w/n;
	if(l%2==0){
		h=1;
	}else{
		h=n;
	}
}else{
	l=w/n+1;
	if(l%2==0){
		h=n-w%n+1;
	}else{
		h=w%n;
	}
}cout<<l<<" "<<h;
	return 0;
}


