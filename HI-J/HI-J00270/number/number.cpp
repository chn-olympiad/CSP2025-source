#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int j=9;j>=0;){
		for(int i=0;i<a.length();){
			if(a[i]==j+48){
				cout<<a[i];	
			}
			i++;
		}
		j--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

