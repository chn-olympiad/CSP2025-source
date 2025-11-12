#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,q=0,s=0,l=0,e=0;
	cin>>n>>m;
	long long a[10005],b[10005];
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n*m;i++){
		b[i]=a[i];
	}
	for(long long i=1;i<=n*m;i++){
		if(a[i]<a[i+1]){
			swap(a[i],a[i+1]);
		}
		for(long long j=1;j<=n*m;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<" ";
//	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==b[1]){
			q=i;
			break;
		}
	}
//	cout<<"         "<<q;
	s=q%n;//0  1
	e=q/n;//1  1
	if(s!=0){
		e++;
	}
	if(e%2==0){
		s++;
	}
	if(s==0){
		s=n;//2
	}
	cout<<e<<" "<<s;
	return 0;
} 
//3%2=1
//3/2=1
//2/2=0
//2 2
//99 100 97 98
//2 
//2 2
//98 99 100 97
//3

//4 4
//100 99 99 99 99 99 99 99 99 99 99 99 99 99 99 99
