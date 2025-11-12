#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("number1.in","r",stdin);
	freopen("number1.out","w",stdout);
	string s;
	int n=0;
	int ans=0;
	int a[10000];
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-48;
			n++;
		}
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='a'&&s[i]<='z')
			continue;
		else
		{
			for(int j=i+1;j<s.size();j++)
			{
				if(s[j]>='a'&&s[j]<='z')
					continue;
				else{
					if(a[j]>a[i]){
						swap(a[i],a[j]);
					}
				}
			}
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]>='a'&&s[i]<='z')
			continue;
		else
			cout<<a[i];
	}
	fclose(stdin);
	fcolse(stdout);
	return 0;
}
