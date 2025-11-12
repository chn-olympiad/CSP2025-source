#include<bits/stdc++.h>
using namespace std;
int l=1e7;
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int k[l],i,m=0;
	cin>>s;
	int h=s.size();
	for(i=0;i<h;i++){
		if(s[i]>='0'  &&  s[i]<='9'){
			k[m]=s[i]-'0';
			m++;
		}
	}
	
	for(i=0;i<m-1;i++){
		for(int j=i+1;j<m;j++){
			if(k[i]<k[j])	swap(k[i],k[j]);
		}
	}
	for(i=0;i<m;i++)		cout<<k[i];
	cout<<endl;
	return  0;
}
