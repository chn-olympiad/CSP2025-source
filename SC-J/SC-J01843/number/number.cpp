#include<bits/stdc++.h>
using namespace std;

const int N=1e+6;

string s; 
int a[N+10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int l=s.size();
	int sum=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			sum++;
			a[sum]=s[i]-'0';
			
		}	
	}
	
	sort(a+1,a+sum+1);
	
	for(int i=sum;i>=1;i--){
		cout<<a[i];
	}
	
	return 0;
} 