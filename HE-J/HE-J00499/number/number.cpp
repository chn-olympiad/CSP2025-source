#include <bits/stdc++.h>
using namespace std;
char s[1000005],n[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int k=0;
	cin>>s;
	for(int i=0;i<1000005;i++){
		if(s[i]==' '){
			break;
		}
		if(s[i]>='0' && s[i]<='9'){
			n[k++]+=s[i];
		}
	}
	sort(n,n+k);
	for(int i=k-1;i>=0;i--){
		cout<<n[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
