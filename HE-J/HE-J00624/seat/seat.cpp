#include <iostream>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,l,k,s,p;
	cin >> n >> m;
	l=n*m;
	for(int i=1;i<=l;i++){
		cin >> a[i];
	}
	k=a[1];
	for(int j=1;j<=l;j++){
		for(int i=1;i<l;i++){
			int t;
			if(a[i]<a[i+1]){
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
		}
	}
	for(int i=1;i<=l;i++){
		if(k==a[i]){
			s=i;
		}
	}
	c=s/n;
	if(s%n!=0){
		c++;
	}
	
	p=s%n;
	if(p==0){
		p=n;
	}
	if(c%2==0){
		r=n-p;
		r++;
	}else{
		r=p;
	}
	cout << c << " " << r;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
