#include<bits/stdc++.h>
using namespace std;
string s,x="";
char a[1000010];
int m=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			m++;
			a[m]=s[i];
		}
	}
	sort(a+1,a+1+m);
	for(int i=m;i>=1;i--){
		x+=a[i];
	}
	cout<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
