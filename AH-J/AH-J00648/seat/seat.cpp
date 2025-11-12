#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[20];
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int b=a[0];
	sort(a,a+n*m);
	int h=1,l=1;
	for(int i=0;i<n*m;i++){
		if(a[i]==b){
			cout<<m-l+1<<" "<<n-h+1;
			return 0;
		}
		if(h==n){
			l++;
		}else if(h==1&&i!=0){
			l++;
		}else if(l%2!=0){
			h++;
		}else if(l%2==0){	
			h--;
		}
	}		
	return 0;
}
