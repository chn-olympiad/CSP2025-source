#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000],t=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>0 && s[i<10]){
			a[t++]=s[i];
		}
	}
	sort(a,a+t);
	for(int i=0;i<t;i++)
	    cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}