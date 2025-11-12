#include<bits/stdc++.h> 
using namespace std;
long long a[1000005];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long j=1;
	long long l=s.size();
	for(int i=0;i<l;i++){
		s[i]-='0';
		if(s[i]>=0&&s[i]<=9){
			a[j]=s[i];
			j++;
		}
	}
	sort(a+1,a+j+1);
	for(int i=j;i>1;i--){
		cout<<a[i];
	}
	return 0;
}
