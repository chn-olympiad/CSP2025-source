#include<bits/stdc++.h>
using namespace std;
int t,n,s[100001];
int a[100001][3];
int p(int w){
	if(a[w][1]<a[w][2]){
		int f=a[w][1];
		a[w][1]=a[w][2];
		a[w][2]=f;
	}
	if(a[w][0]<a[w][1]){
		int f=a[w][0];
		a[w][0]=a[w][1];
		a[w][1]=f;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=0;j<t;j++){
		cin>>n;
		s[j]=0;
		for(int i=0;i<n;i++){
			cin>>a[i][0];
			cin>>a[i][1];
			cin>>a[i][2];
			p(i);
			p(i);
			s[j]=s[j]+a[i][0];
		}
		if(s[j]==6){
			s[j]=s[j]-2;
		}
		if(s[j]==14){
			s[j]=s[j]-1;
		}
	}
	for(int i=0;i<t;i++){
		cout<<s[i]<<endl;
	}
	return 0;
} 
