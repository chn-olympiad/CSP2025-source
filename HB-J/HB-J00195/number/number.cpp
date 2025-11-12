#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int a[1000005];
/*bool cmp(int a,int b){
	if(a>=b)return true;
	else return false;
}*/
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int j=0;
	while(cin>>s[j])j++;
	for(int i=0;i<j;i++){
		if(s[i]>=48&&s[i]<=57){
			a[i]=(int)s[i]-48;
			//cout<<"a["<<i<<"]="<<a[i]<<endl;
		}
		else{
			a[i]=-1;
		}
	}
	sort(a,a+j);
	for(int i=j-1;i>=0;i--){
		if(a[i]!=-1){
			cout<<a[i];
		}
	}
	return 0;
}
