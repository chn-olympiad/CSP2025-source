#include <bits/stdc++.h>
using namespace std;
bool cmp(int A,int B){
	return A>B;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,a[110],l=1,h=0;
	cin>>n>>m;
	long long t=m*n;
	for(int i=0;i<t;i++){
		cin>>a[i];
	}
	long long b=a[0];
	sort(a,a+t,cmp);
	for(int i=0;i<t;i++){
		if(l%2!=0){
			h++; 
		}else{
			h--;
		}
		if(h>n){
			h=n;
			l++;
		}else if(h<=0){
			h=1;
			l++; 
		}
		if(a[i]==b){
			cout<<l<<" "<<h;
			break;
		}
	}
	return 0;
}