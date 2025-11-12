#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000020];
int r;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,-1,sizeof(a));
	cin>>s;
	int p=s.size();
	for(int i=0;i<p;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[r]=s[i];
			r++;
		}
	}
	sort(a,a+p);
	for(int j=p-1;j>=0;j--){
		if(a[j]!=-1){
			cout<<int(a[j]-48);
		}
	}
	return 0;
}
