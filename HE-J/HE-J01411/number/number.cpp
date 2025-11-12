#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	int n=s.size(),l=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9') {
		a[l]=s[i]-48;	
		l++;
		}
	}
	sort(a,a+l);
	while(l>0){
		cout<<a[l-1];
		l--;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
