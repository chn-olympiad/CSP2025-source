#include<bits/stdc++.h>
using namespace std;
int n,m,z,top,s,t[12][12];
struct js{
	int bh,cj;
}a[120];
bool cmp(js a,js b){
	return a.cj>b.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	z=n*m;	
	for(int i=1;i<=z;i++){
		cin>>a[i].cj;
		a[i].bh=i;
	}
	sort(a+1,a+z+1,cmp);
	int q=0;
	while(s!=1){
		q++;
		s=a[q].bh;		
	}
	cout<<q<<endl;
	if(q%n==0){
		cout<<q/n<<" ";
		if(q/n%2==0){
			cout<<1;
		}
		else cout<<n;
	}
	else{
		cout<<q/n+1<<" ";
		if((q/n+1)%2==0){
			cout<<n-(q%n)+1;
		}
		else cout<<q%n;
	}	
	return 0;
}
