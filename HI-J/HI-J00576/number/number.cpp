#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long a,b=0;
	long long s[100005]={};
	cin>>a;
	while(a>0){
		s[b]=a%10;
		a/=10;
		b++;
	}
	for(int i = 0;i<b;i++){
		for(int j = 0;j<=i;j++){
			if(s[i]>s[j]){
				swap(s[i],s[j]);
			}
		}
	}
	for(int i = 0;i<b;i++){
		cout<<s[i];
	}
	return 0;
}

