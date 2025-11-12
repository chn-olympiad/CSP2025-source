#include<iostream>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char box;
	string s;
	cin>>s;
	int l,j=0;
	l = s.size();
	char a[l];
	for(int i=0;i<l;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[j] = s[i];
			j++;
		}
	}
	for(int i=0;i<=j;i++){
		for(int k=0;k<=j;k++){
			if(a[k]<a[k+1]){
				box = a[k];
				a[k]=a[k+1];
				a[k+1]=box;
			}
		}
	}
	for(int i=0;i<=j;i++){
		cout<<a[i];
	}
	return 0;
} 
