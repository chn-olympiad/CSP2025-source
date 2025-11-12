#include<bits/stdc++.h>
using namespace std;
long long num=0;
string s,a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[num]=s[i];
			num++;
		}
	}
	for(int i=0;i<num;i++){
		for(int j=i+1;j<num;j++){
			if(a[i]<a[j]){
				int t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
		}
	}
	for(int i=0;i<num;i++){
		cout<<a[i];	
	}
	return 0;
}
