#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	int a[101],b,l,h;
	cin>>n>>m;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	for(int i=0;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n*m;i++){
		a[0]=c;
		if(a[i]>=a[i-1]){
			b=a[i-1];
			a[i-1]=a[i]
			a[i]=b;
		}
	} 
	for(int i=0;i<=n*m;i++){
		if(a[i]==c){
			while(i>n){
				h=i;
				h=h-n;
				l++;
			}
			cout<<l+1<<" ";
			if(l%2==0){
				cout<<h;
			}else{
				cout<<n+1-h;
			}
			
		}
	} 
	fclose(stdin);
	fclose(stdout);
return 0;
}
