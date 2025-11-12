#include<bits/stdc++.h>
using namespace std;
long long a[1010101];
long long n,k,l=0,x,y,x2=0,y2;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1; i <= n; i++)
	scanf("%d",&a[i]);
	for(int i = x2+1; i <= n; i++){
		for(int j = x2+1; j <= i; j++){
			int q=0;
			if(i!=j){
				q=a[j];
				for(int i2 = j; i2 < i; i2++){
					q+=(q^a[i2+1]);
				}
			}
			else q=a[i];
			if(q==k&&a[j]!=0) {
				l++;
				x2=i;
			}
			else if(a[j]==0&&k==0&&q==0){
				l++;
			}
		}
	}
	cout<<l;
	return 0;
}