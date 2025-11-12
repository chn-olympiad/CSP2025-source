#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int s[20][20],m,n,a[105];
	cin>>n>>m;
	for(int i=0;i<m*n;i++){
		cin>>a[i];
	}
	int c=a[1];
	sort(a,a+m*n);
	int b[105],j=0;
	for(int i=m*n;i>0;i--){
		b[j]=a[i-1];
		j++;
	}
	int zf=0,mi=1,ni=1;
	for(int i=0;i<n*m;i++){
		if(zf==0){
			s[ni][mi]=a[i];
			if(s[ni][mi]==c){
				cout<<ni<<" "<<mi;
			}
			if(i%n!=n){
				++mi;
			}
			else{
				++ni;
				zf=1;
			}
		}
		else{
			s[ni][mi]=a[i];
			if(s[ni][mi]==c){
				cout<<ni<<" "<<mi;
			}
			if(i%n!=1){
				--mi;
			}
			else{
				++ni;
				zf=0;
			}
		}
	}
	return 0;
} 
