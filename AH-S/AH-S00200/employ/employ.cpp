#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int sum=0;
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)
		cin>>c[i];
	for(int i=0;i<n;i++)
		for(int j=i;i<n;j++){
			if(c[i]>c[j])
				swap(c[i],c[j]);
		}
	for(int i=0;i<n-1;i++)
		if(c[i]==c[i+1])
			sum++;
	cout<<sum<<endl;
	return 0;
}
