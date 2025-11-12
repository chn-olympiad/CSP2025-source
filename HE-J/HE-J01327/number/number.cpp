#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char a[N];
int ans,n;
int num[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<N;i++){
		if(s[i]){
			ans++;
		}
		else{
			break;
		}
	}
	for(int i=0;i<ans;i++){
		if(s[i]>='0'  && s[i]<='9'){
			a[n]=s[i];
			n++;
		}
	}
	for(int i=0;i<n;i++){
		num[i]=a[i]-48;
	}
	sort(num,num+n);
	for(int i=n-1;i>=0;i--){
		cout<<num[i];	
	}
	
	return 0;
} 
