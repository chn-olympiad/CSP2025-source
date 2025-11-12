#include<bits/stdc++.h>
using namespace std;
int s[5005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	int f=0;
	for(int i=0;i<n;i++){
		cin>>s[i];
		if(s[i]>f)
		f=s[i];
	}
	if(f==1)
	{
		cout<<n-2;
		return 0;
	}
	sort(s,s+n,cmp);
	int d=0;
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(s[i]+s[j]+s[k]>s[i]*2)
				d++;
			}
		}
	}
	cout<<d;
	return 0;
}
