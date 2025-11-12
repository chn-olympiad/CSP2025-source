#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
	freopen("testin","number",stdin);
	freopen("testout","number",stdout);
	int s,i,n;
	cin>>s;
	n=s;
	while(n>0){
		n=n/10;
		i++;
	}
	for(int j=0;j<i;j++){
		a[j]=s%10;
		s=s/10;
	}
	for(int j=0;j<i;j++){
		if(a[j]<a[j+1]){
			swap(a[j],a[j+1]);
		}
	}
	for(int j=0;j<i;j++){
		if(a[j]<a[j+1]){
			swap(a[j],a[j+1]);
		}
	}
	for(int j=0;j<i;j++){
		cout<<a[j];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
