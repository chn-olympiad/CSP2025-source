#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long a[N],k=0,ans=0,l=1;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<=sizeof(s);i++){
		s[i]=',';
	}
	cin>>s;
	for(int i=sizeof(s);i>=0;i--){
		s[i+1]=s[i];
	}
	k=0;
	ans=0;
	while(s[l]!=','){
		if(s[l]=='0'){
			ans++;
		}
		if(s[l]=='1'){
			k++;
			a[k]=1;
		}
		if(s[l]=='2'){
			k++;
			a[k]=2;
		}
		if(s[l]=='3'){
			k++;
			a[k]=3;
		}
		if(s[l]=='4'){
			k++;
			a[k]=4;
		}
		if(s[l]=='5'){
			k++;
			a[k]=5;
		}
		if(s[l]=='6'){
			k++;
			a[k]=6;
		}
		if(s[l]=='7'){
			k++;
			a[k]=7;
		}
		if(s[l]=='8'){
			k++;
			a[k]=8;
		}
		if(s[l]=='9'){
			k++;
			a[k]=9;
		}
		l++;
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--){
		cout<<a[i];
	}
	for(int i=1;i<=ans;i++){
		cout<<0;
	}
	return 0;
}
