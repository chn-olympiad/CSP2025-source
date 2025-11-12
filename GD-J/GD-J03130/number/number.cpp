#include  <bits/stdc++.h>
using namespace std;
int e,c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string a;
	cin>>a;
	int n=a.size();
	int b[1000000];
	c=0;
	for(int i=0;i<n;i++){
		int m=int(a[i])-48;
		if(m>=0&&m<=9){
			b[c]=m;
			c++;	
		}
	}
	for(int i=0;i<c-1;i++){
		int Max=-1,max_=0;
		for(int j=i;j<c;j++){
			if(b[j]>Max){
				Max=b[j];
				max_=j;
			}
		}
		b[max_]=b[i];
		b[i]=Max;
	}
	int d=b[0];
	for(int i=1;i<c;i++){
		d=d*10+b[i];
	}
	cout<<d<<' ';
	return 0;
}
