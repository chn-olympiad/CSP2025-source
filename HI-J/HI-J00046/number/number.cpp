#include<bits/stdc++.h>
using namespace std;
int s[10000],sum=0;
string d;
char r;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>d;
	long long n=d.size();
	for(int i=0;i<n;i++){
		r=d[i];
		if(r>=48&&r<=59){
			sum+=1;
			s[sum]=r-48;
			sort(s+1,s+sum+1);
		}
	}
	for(int i=sum;i>0;i--){
		cout<<s[i];
	}
	return 0;
} 
