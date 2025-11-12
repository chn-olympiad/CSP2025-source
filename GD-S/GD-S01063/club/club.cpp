#include<bits/stdc++.h>
using namespace std;
int s[100100][3],s1=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a;
	cin>>a;
	for(int i=0;i<a;i++){
		int n;
		cin>>n;
		int n2=n/2;
		for(int i=0;i<n;i++){
			cin>>s[i][0]>>s[i][1]>>s[i][2];
			s1+=max(max(s[i][0],s[i][1]),max(s[i][1],s[i][2]));
		}
	cout<<s1;
	}
	
} 
