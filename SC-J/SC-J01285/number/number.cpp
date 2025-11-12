#include<bits/stdc++.h>
using namespace std;
char a[100001]={-1};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
			a[i]=s[i];
		}
	}
	sort(a+1,a+n+1);
	for(int i=0;i<=n/2;i++){
		swap(a[i],a[n-i]);
	}
	for(int i=0;i<=n;i++){
		if(a[i]=='9'){
			cout<<a[i];
		}else if(a[i]=='8'){			
			cout<<a[i];
		}else if(a[i]=='7'){
			cout<<a[i];
		}else if(a[i]=='6'){
			cout<<a[i];
		}else if(a[i]=='5'){
			cout<<a[i];
		}else if(a[i]=='4'){
			cout<<a[i];
		}else if(a[i]=='3'){
			cout<<a[i];
		}else if(a[i]=='2'){
			cout<<a[i];
		}else if(a[i]=='1'){
			cout<<a[i];
		}else if(a[i]=='0'){
			cout<<a[i];
		}
	}
	cout<<endl;
	return 0;
} 