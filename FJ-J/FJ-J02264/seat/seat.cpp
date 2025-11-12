#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1,a[105],seat[15][15],r=1,c=1,which=0;
	bool s=1,down=1;
	cin>>n>>m;
	cin>>a1;
	a[0]=a1;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		if(a[i]!=i)s=0;
	}
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++){
		if(a1==a[i])which=i+1;
	}
	if(s==1)cout<<m<<" "<<n<<endl;
	else{
		for(int i=0;i<which;i++){
			if(down==1&&r!=n){
				r++;
			}
			else if(down==0&&r!=1){
				r--;
			}
			else{
				if(r==n){
					c++;
					down=0; 
				}
				else{
					c++;
					down=1;
				}
			}
		}
		cout<<c<<" "<<r<<endl;
	}
	return 0;
} 
