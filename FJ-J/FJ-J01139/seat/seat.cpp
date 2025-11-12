#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,a[1001]={},r,h,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=(n*m);i++){
		cin>>a[i];
	}r=a[1];
	sort(a+1,a+1+(n*m),greater<int>());
	h=1;l=1;
	for(int i=1;i<=(n*m);i++){
	//	cout<<a[i]<<" "<<h<<" "<<l<<endl;
		if(a[i]==r){
			cout<<h<<" "<<l;
			break;
		}else{
			if(h%2!=0){
			l++;
			if(l>n){
				l=n;h++;
			}
			}else{
			l--;
			if(l==0){
				l=1;h++;
			}	
			}
		}
	}
	return 0;
}
