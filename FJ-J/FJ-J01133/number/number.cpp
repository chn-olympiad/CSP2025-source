#include<bits/stdc++.h>
using namespace std;
string str;
int a[1000005],p=-1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<int(str.size());i++){
		if(isdigit(str[i])){
			a[++p]=int(str[i]-'0');
		}
	}
	sort(a+0,a+p+1);
	for(int i=p;i>=0;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
*/
