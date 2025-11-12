#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i =0;i<s.size();i++){
		if(s[i]-48>=0&&s[i]-48<=9){
			a[n]=s[i]-48;
			n++;
		}
	}
	sort(a,a+n);
	int cnt=0;
	for(int i =0;i<n;i++){
		cnt+=a[i]*pow(10,i);
	}
	printf("%d",cnt);
	return 0;
}
