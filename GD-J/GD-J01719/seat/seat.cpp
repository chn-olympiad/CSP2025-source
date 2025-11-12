#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,cc=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	    cin>>a[i];
	int zz=a[1];
	sort(a,a+n*m);
	for(int i=1;i<=n*m/2;i++){
		swap(a[i],a[n*m-i-1]);
	}
	while(m--){
		if(cc%2==1){
			for(int i=1;i<=n;i++){
				if(zz==a[(cc-1)*n+i])
					cout<<cc<<" "<<i;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(zz==a[(cc-1)*n+i])
					cout<<cc<<" "<<n-i+1;
			}
		}
		cc++;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
