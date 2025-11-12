#include <bits/stdc++.h>
using namespace std;
bool sb(int a,int b){
	return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[1000],b,m,n,l;
    cin>>n>>m;
    cin>>b;
    a[0]=b;
    int j=1;
    while(cin>>a[j]){
		j++;
	}
	sort(a,a+j,sb);
	for(int i=0;a[i]!=b;i++){
		l=i+2;
		}
	if(l%n==0){
		if(l/n%2==0){
			cout<<l/n<<' '<<'0';
		}else{
			cout<<l/n<<' '<<n;
		}
	}else{
		if((l/n+1)%2==0){
			cout<<l/n+1<<' '<<n-l%n+1;
		}else{
			cout<<l/n+1<<' '<<l%n;
		}
	}
    return 0;
    }
