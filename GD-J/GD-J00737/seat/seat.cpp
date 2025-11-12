#include<bits/stdc++.h> 
#define int long long
using namespace std;
inline int read(){
	char ch;
	int sum=0,x=1;
	ch=getchar();
	while(ch<'0'||(ch>'9')){
		if(ch=='-')x=-1;
		ch=getchar(); 
	}
	while((ch>='0')&&(ch<='9')){
		sum=(sum<<3)+(sum<<1)+(ch^48);
		ch=getchar();
	}
	return sum*x;
}
//zzzzzz
int n,m,a[200],x,sum;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n*m;i++){
		a[i]=read();
	}
	x=a[1];
	sort(a+1,a+1+n*m,greater<int>() );
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[++sum]==x){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[++sum]==x){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
