#include<bits/stdc++.h>
using namespace std;
int a[120],n,m,ar,ri;
bool cmp(int a,int b){
	return a>b;
}
void sort1(){
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m-i;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>ar;
	a[1]=ar;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort1();
	for(int i=1;i<=n*m;i++){
		if(a[i]==ar){
			ri=i;
			i=n*m+1;
		}
	}
	if(!(ri%n)){
		if(ri/n%2){
			cout<<ri/n<<' '<<n;
		}
		else{
			cout<<ri/n<<' '<<1;
		}
	}
	else{
		cout<<(ri/n)+1<<' ';
		if ( ( (ri/n)+1 )%2 ){
			cout<<ri%n;
		}
		else{
			cout<<n-(ri%n)+1;
		}
	}
	return 0;
}
