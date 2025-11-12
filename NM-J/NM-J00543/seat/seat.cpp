#include<bits/stdc++.h>
using namespace std;
bool com(int a,int b){
    return a>b;
}
int main(){
	int n,m;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[m][n],b[10005],c=0,d;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
		c++;
		if(i==1)
		{
			d=b[i];
		}
	}
	int e=0;
	sort(b,b+c,com);
	for(int i=1;i<=n*m;i++){
		if(b[i]==d){
			if((i+1)%n==0){
				e=n;
			}
			else{
				e=(i+1)%n;
			}
			cout<<i/n+1<<" "<<e;
			return 0;
		}
	}

    return 0;
}
