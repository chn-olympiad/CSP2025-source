#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int L,R;
int n;
int a[N];
int Find(int x){
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(x==a[mid]){
			return mid;
		}
		if(x>a[mid]){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return l;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>L>>R;
    n=L*R;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int u=a[1];
    sort(a+1,a+n+1);
    int k=0;
    for(int i=1;i<=n;i++){
		if(a[i]==u){
			k=i;
			break;
		}
	}
    k=n-k+1;
    int jk=0;
    for(int i=1;i<=R;i++){
		if(i%2==1){
			for(int j=1;j<=L;j++){
				jk++;
				if(jk==k){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=L;j>=1;j--){
				jk++;
				if(jk==k){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
    return 0;
}
