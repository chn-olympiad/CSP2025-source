#include <iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,w;
	cin >> n >> m;
	int a[n*m];
	int b[n*m];
	int q=n*m;
	for (int i=0;i<q;i++){
		cin >> a[i];
	} 
	w=a[0];
	q=n*m;
	for (int i=0;i<q;i++){
		int l=a[i],f=0;
		for(int j=i;j<q;j++){
			if(l>a[j]){
				f=j;
			}
			l=min(l,a[j]);
			a[j]=101;
		}
		b[i]=l;
	}
	int p=0;
	for (int i=0;i<q;i++){
		if(b[i]==w){
			p=i+1;
			break;
		}
	}
	int y;
	if((p/n+1)%2==0){
		y=n+1-p%n;
	}
	else{
		y=p%n;
	}
	cout << m-(p/n) << ' ' << y;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 