#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int sr=a[1];
	for(int i=1;i<n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[i]<a[j]){
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}	
	int ssri;
	for(int i=1;i<=n*m;i++){
		if(a[i]==sr){
			ssri=i;
			break;
		}
	}
	int h,l;
	h=ssri/n+1;
	l=ssri-(h-1)*n;
	if(l==0){
		h--;
		l=n;
	}
	cout<<h<<" ";
	if(h-h/2*2==1){
		cout<<l;
	}else{
		cout<<n-l+1;
	}
	return 0;
}
