#include<iostream>
using namespace std;
int b[10000];
int m(int o){
	int k;
	int sum=0;
	for(int i=1;i<=o;i++){
		sum+=b[i];
		k=max(b[i],b[i+1]);
	}
	if(sum>2*k){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	int n;
	cin>>n;
	int a[n+1];
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		int h=max(a[1],max(a[2],a[3]));
		if(a[1]+a[2]+a[3]>2*h){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	b[1]=a[1];
	b[2]=a[2];
	b[3]=a[3];
	int o=0;
	
	for(int i=3;i<=n;i++){
		int p=0;
		int u=1;
		b[1]=a[1];
	b[2]=a[2];
	b[3]=a[3];
		while(1){
			p++;
			if(m(i)==1){
				o++;
			}
			for(int i1=1;i1<=n;i1++){
				cout<<b[i1]<<' ';
			}
			cout<<endl;
			if(i+p>=n&&u==i){
				break;
			}
			if(i+p>=n&&u<i){
				p=1;
				u++;
			}
			cout<<o<<endl;
			b[u]=a[i+p];
		
		}
		
	}
	cout<<o;
	return 0;
}
