#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int b=0;
	char n,h,a[10010];
	for(int i=0;i<s.size();i++){
		n=s[i];
		if(n=='1'||n=='2'||n=='3'||n=='4'||n=='6'||n=='5'||n=='8'||n=='7'||n=='9'||n=='0'){
			a[b]=n;
			b=b+1;
		}
	}
	for(int j=0;j<b;j++){
		for(int i=0;i<b;i++){
			if(a[i]<a[i+1]){
				h=a[i];
				a[i]=a[i+1];
				a[i+1]=h;
			}
		}
	} 
	
	for(int i=0;i<b;i++){
		cout<<a[i];
	}
	fclose(stdin);	
	fclose(stdout);
	return 0;
} 
