#include<bits/stdc++.h>
using namespace std;
string s;
int a[100010];
int k,c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		a[i]=s[i]-'0';
	}
	for(int i=0;i<=s.size();i++){
		for(int j=0;j<=s.size()-i;j++){
			if(a[j+1]>a[j]){
			    k=a[j+1];
			    a[j+1]=a[j];
			    a[j]=k;
		    }
		}	
	}
	for(int i=0;i<=s.size()-1;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 