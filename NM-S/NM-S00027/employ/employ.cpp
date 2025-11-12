#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int num=1;
	char s[505];
	cin>>s[505];
	int c[505];
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		if(c[i]>c[i+1])
		{
			num++;
			break;
		}
	}
	cout<<num;
	return 0;
}
