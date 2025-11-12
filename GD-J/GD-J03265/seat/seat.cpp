#include<bits/stdc++.h>
using namespace std;

int a[105],pos;
int n,m;

bool cmp(int a,int b) {
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	pos=a[1];
	cout<<pos<<endl;
	sort(a+1,a+n*m+1,cmp); 
	cout<<endl;
	for(int i=0;i<n;i++){
		if(i%2==0){
			for(int j=1;j<=m;j++){
				if(a[i*m+j]==pos) cout<<i+1<<" "<<j;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				if(a[i*m+m-j+1]==pos) cout<<i+1<<" "<<j;
			}
		}
	}
	return 0;
}
