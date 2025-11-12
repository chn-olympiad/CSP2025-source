#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10002];
long long listnum=1;
long long r=1,c=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(long long i=2;i<=n*m;i++){
		cin>>a[i];
        if(a[i]>a[1]){
            listnum+=1;
        }
	}
	if(listnum%n==0){
		c=listnum/n;
	}else{
		c=listnum/n+1;
	}
    if(c%2==1){
		r=listnum-(c-1)*n;
    }else{
		r=n-(listnum-(c-1)*n)+1;
    }
    cout<<c<<" "<<r;
    cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
