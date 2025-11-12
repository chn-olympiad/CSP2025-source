#include<bits/stdc++.h>
using namespace std;
string s;
long long a[54088],z=0,b=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i>=0;i++){
		if(s[i]==0&&s[i+1]==0&&s[i+2]==0){
			break;
		}
		z++;
	}
	for(int i=0;i<z;i++){
		if(s[i]>=0&&s[i]<=9){
			a[i]=s[i];
			b++;
		}
	}
	for(int i=0;i<b-1;i++){
		for(int e=i+1;e<b;e++){
			if(a[e]>a[i]){
				z=a[i];
				a[i]=a[e];
				a[e]=z;
			}
		}
	}
	if(s[1]>s[0]){
		z=s[1];
		s[1]=s[0];
		s[0]=z;
	}
	cout<<s;
	return 0;
} 
