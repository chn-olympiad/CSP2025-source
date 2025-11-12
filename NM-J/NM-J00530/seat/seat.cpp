#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	long long c=1,r=1;
	cin>>n>>m;
	long long num;
	num=n*m;
	int num1=num+10;
	int s[num1];
	for(int i=0;i<num;i++){
		cin>>s[i];
	}
	for(int i=0;i<num;i++){
		if(s[0]<s[i]){
			if(r%2!=0){
				c++;
			}else{
				c--;
			}
		}
		if(c>n){
			r++;
			c--;
		}else if(c<1){
			r++;
			c++;
				}
	}
	cout<<r<<" "<<c;
	
	return 0;
}
