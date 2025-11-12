#include<bits/stdc++.h>
using namespace std;
int a[10000000];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int j=1;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	j--;
	bool temp=1;
	for(int i=1;i<=j;i++){
		if(temp&&i==2)break;
		for(int k=i+1;k<=j;k++){
			if(a[k]>a[i]){
				swap(a[i],a[k]);
				temp=0;
			}
		}
	}
//	cout<<j;忘了sort怎么用，我也是个神人 
	for(int i=1;i<=j;i++)cout<<a[i];
	return 0;
} 
