#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int l[10000000]={};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long a,b,c=0;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>l[i];
	}
	sort(l+1,l+a,cmp);
	for(int i=1;i<=a;i++){
		for(int k=i;k<=a;k++){
			if(i!=k and l[i]!=0 and l[k]!=0 and l[i]!=b and l[k]!=b)if(l[i]+l[k]==b or l[i]-l[k]==b or l[k]-l[i]==b)c++;
		}
	}
	for(int i=1;i<=a;i++){
		if(l[i]==b)c++;
	}
	cout<<c;
}
