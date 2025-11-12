#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main()
{
	//freopen("testin","polygon",stdin);
	//freopen("testout","polygon",stdout);
	int n,s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]+a[j]>a[i+1]&&a[i]+a[j]>a[j+1]){
				s++;
			}
		}
	}
	cout<<s-2*5;
//	fclose(stdin);
	//fclose(stdout);
	return 0; 
} 
