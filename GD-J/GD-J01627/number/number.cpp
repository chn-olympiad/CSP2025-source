#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;              
	int a[1000005];
	int sum=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			sum++;
			a[sum]=s[i]-'0';
			//cout<<a[sum]<<" "<<sum<<endl;
		}
	}
	for(int i=1;i<=sum;i++){
		for(int j=1;j<=sum;j++){
			if(a[j]<a[j+1]){
				int c=a[j];
				a[j]=a[j+1];
				a[j+1]=c;
			}
		}
	}
	for(int i=1;i<=sum;i++) cout<<a[i];
	return 0;
} 
