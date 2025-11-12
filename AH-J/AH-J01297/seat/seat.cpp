#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[105],b[105],m,n,t;
bool c(int q,int w){return q>w;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
        cin>>a[i];
        b[i]=a[i];
	}
	sort(b+1,b+n*m+1,c);
	for(int i=2;i<=n*m;i++){
        if(a[1]>b[i]){
            int p=i-1;
            cout<<(p%n==0?p/n:p/n+1)<<" "<<((p-1)/n%2==0?(p%n==0?p/n+1:p-p/n*n):n*2-p+1);
            return 0;
        }
	}
	cout<<m<<" "<<n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
