#include<iostream>
using namespace std;
int a[110]={0};
int n,m,r,s,c;
int main(){
 	freopen("seat.in","r",stdin);
 	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;
	a[0]=r; 
	for (int i=1;i<n*m;i++){
		cin>>s;
		if(s>r){
			a[c]=s;
			c++;
		}
	}
	for(int i=c;i>0;i--){
		for(int j=0;j<i;j++){
			if(a[j]<a[j+1]){
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(int i=0;i=c;i++){
		if(a[i]=r){
			c=i+1;
			break;
		} 
	}
	if(c%n==0){
		cout<<c/n<<' '<<n;
	}else{
		cout<<c/n+1<<' ';
		if((c/n)%2!=0){
			cout<<n-c%n+1;
		}else{
			cout<<c%n;
		}
	}
	return 0;
}
