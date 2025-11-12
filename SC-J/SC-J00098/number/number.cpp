#include<bits/stdc++.h>
using namespace std;
bool sf(int A,int B);
bool sf(int A, int B){
	return A<B;
} 
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
	string s;
	int j,i;
	int a[1000];
		cin>>s;
	if(s.size()==1)
	{
		cout<<s;
		
	}
	for(int j=0;j<s.size();j++){
		for(int i=0;i<=9;i++){
			if(s[j]==i){
				a[j]=i;
				
				
			}
		}	
	}
	sort(a,a+j,sf);
	cout<<a[j];
fclose(stdin);
fclose(stdout);	
	return 0;
} 