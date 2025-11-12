#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int map[11][11],c,l,r,n,m,change[129],a[129];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;
	change[0]=r;
	for(int i=1;i<n*m;i++){
		cin>>change[i];
	}
	sort(change,change+m*n);
	for(int i=0;i<n*m;i++){
		a[i]=change[n*m-1-i];
	}
	int num;
	for(int i=0;i<n*m;i++){
		if(r==a[i]){
			num=i+1;
			break;
		}
	}
	c=num/n;
	int ex=num%n;
	if(c%2==0){
		if(ex==0)  cout<<c<<" "<<1;
		else{
			cout<<c+1<<" "<<ex<<endl;
		}
	}else{
		if(ex==0)  cout<<c<<" "<<n;
		else{
			cout<<c+1<<" "<<n-ex+1<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


