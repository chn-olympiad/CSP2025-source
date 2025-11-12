#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
//	scanf("%s",&s);
	int l=s.size();
	int a[l+1];
	for(int i=0;i<=l;i++){
		a[i]=0;
	}
	int w=0;
	for(int i=0;i<=l-1;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[w]=s[i]-'0';
			w++;
		}
	}
	for(int i=0;i<=l-1;i++){
		for(int j=i+1;j<=l-1;j++){
			int m=0;
			if(a[i]<a[j]){
				m=a[i]+a[j];
				a[i]=m-a[i];
				a[j]=m-a[j];
			}
		}
	}
	
	int sum=0;
	for(int i=0;i<=l;i++){
		if(a[i]!=0){
			cout<<a[i];
		}
		else{
			if(sum<l){
				cout<<0;
			}
			else{
				return 0;
			}
		
		}
		sum++;
	}
	return 0;
	//jei
}
