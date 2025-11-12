#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[105],t,w1,w2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		b[i]=a[n*m+1-i];
	}
	for(int i=1;i<=n*m;i++){
		if(b[i]==t){
			w2=i;break;	
		}
	}
	w1=w2/n;
	w2=w2%n;
	if((w1+1)%2==1&&w2!=0){
		cout<<w1+1<<" "<<w2;
	}else if((w1+1)%2==0&&w2!=0){
		cout<<w1+1<<" "<<m-w2+1;
	}else if(w2==0){
		if(w1%2==1){
			cout<<w1<<" "<<m;
		}else{
			cout<<w1<<" "<<1;
		}
	}
	return 0;
}
