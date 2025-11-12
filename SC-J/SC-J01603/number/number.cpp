#include<bits/stdc++.h>
using namespace std;
char c[1000005];
int a[1000005];
int k,n=1,ans=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c;
	for(int i=0;i<=strlen(c)-1;++i){	
		if(c[i]>='0' && c[i]<='9'){
			k++;
			a[k]=c[i]-48;
		}
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;--i){
		cout<<a[i];
	}
    fclose(stdin);
	fclose(stdout);
	return 0;
}