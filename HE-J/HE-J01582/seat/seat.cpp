#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110],o=0,q=0,p=0,lie=1,t=0;
int main(){
    freopoen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
cin>>a[i];
}
o=a[1];
for(int i=1;i<=n*m;i++){
	for(int j=i+1;j<=n*m;j++){
		if(a[i]<a[j]){
			swap(a[i],a[j]);
		}
	}
}
for(int i=1;i<=n*m;i++){
	if(o==a[i]){
		q=i;
		break;
	}
}
if(q==m){
	cout<<1<<" "<<q;
}
else if(q<m){
	cout<<1<<" "<<q;
}
else if(q>m){
	for(int i=1;i<=10;i++){
		if(q>m){
			q-=m;
			lie++;
		}
		if(q<m){
			if(lie%2==0){
				cout<<lie<<" "<<n-q+1;
				return 0;
			}
			else if(lie%2!=0){
				cout<<lie<<" "<<q;
				return 0;
			}
		}
	}
}
	return 0;
}
