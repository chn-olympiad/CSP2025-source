#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long sum=n*m;
	for(long long i=1;i<=sum;i++){
		cin>>a[i];
	}
	int b=a[1];
	for(long long i=2;i<=sum;i++){
		if(a[i]>a[i-1]){
			swap(a[i-1],a[i]);
		}
	}
	if(a[1]==b){
		cout<<1<<" "<<1;
	}

	else{
		for(long long i=1;i<=sum;i++){
			if(a[i]==b){
				if(i<=n){
					cout<<1<<" "<<i;
				}
				else if(i==sum){
					cout<<m<<" "<<n;
				}
				else{
					if(i-n==1){
						cout<<n*m-i+1<<" "<<n;
					}
					else if((i-n)-((i/m-1)*n)==1){
						cout<<n*m-i+1<<" "<<1;
					}
					else{
						if((i/m)%2==0){
							cout<<n*m-i+1<<" "<<n+(i%n);
						}
						else{
							cout<<n*m-i+1<<" "<<1+(i%n);
						}
					}
				}

			}
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
