#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000001];
	long long a[1000001];
	int j=1,i=1;
	while(cin>>s[i]){
		if(0<=s[i] && 9>=s[i]){
			a[j]=s[i];
			j++;
		}
		i++;
	}
	for(int i=1;i<=j;i++){
		for(int k=i+1;k<=j;k++){
			if(a[i]<a[k]) swap(a[i],a[k]);
		}
	}
	for(i=1;i<=j;i++){
		cout<<a[i];
	}
	return 0;
}
