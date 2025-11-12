#include<bits/stdc++.h>
using namespace std;
int n,m,a[402],target,grand,c,r;
int main(){
	//The below are freopens.
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    //Done.
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)target=a[i];
	}
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=n*m;i++)if(a[i]==target)grand=i;
    c=(grand+2*n-1)/(2*n);
    r=grand%(2*n);
    if(r==0)r=2*n;
    //cout<<grand<<" "<<c<<" "<<r<<endl;
    c=2*c-1;
    if(r>n){
		c++;
		r=(2*n+1)-r;
	}
	cout<<c<<" "<<r;
    return 0;
}
