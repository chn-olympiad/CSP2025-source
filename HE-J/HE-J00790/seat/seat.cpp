#include<bits/stdc++.h>
using namespace std;
int n,m,nums,c=1,r=1,a[105],ai=1;
bool k=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	} nums=a[1];
	sort(a+1,a+n*m+1,cmp);
	 //for(int i=1;i<=n*m;i++) cout << a[i] <<" ";
	 //cout << endl;
	k=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++,ai++){
			if(a[ai]==nums){
				//cout << r <<" "<< c <<" "<< ai <<" "<< a[ai] << endl;
				k=0;
				break;
			}
			if(j!=n){
				if(i%2==1) r++;
				else r--;
			}
			 //cout << r <<" "<< c <<" "<< ai <<" "<< a[ai] << endl;
		} if(k==0) break;
		if(i!=m) c++;
		 //cout << r <<" "<< c <<" "<< ai <<" "<< a[ai] << endl;
	}
	cout << c <<" "<< r;
	 //cout <<" "<< ai <<" "<< a[ai] << endl;
	 //cout << nums;
	return 0;
}
