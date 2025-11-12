#include<bits/stdc++.h>
using namespace std;
long long k,n,a[100006];
string b[100006],k1;
string f(long long x){
	string s;
	while(true){
		s=s+char(x%2+48);
		x=x/2;
		if(x==0){
			return s;
		}
	}
}
int ji(string k1){
	string s1,s2;
	int ff=0,fff=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int p=1;p<=max(s1.size(),b[j].size());p++){
				if(s1[p]!=b[j][p]){
					s1[p]=1;
				}
				else{
					s1[p]=0;
				}
			}
			if(s1.size()>k1.size()){
				s1=s2;
			}
			else if(s1.size()==k1.size()){
				for(int p=1;p<=s1.size();p++){
					if(s1[p]!=k1[p]){
						ff=1;
						break;
					}
				}
				if(ff==0){
					fff++;
				}
				else{
					ff=0;
				}
			}
		}
	}
	return fff;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	k1=f(k);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=f(a[i]);
	}
	cout<<ji(k1);
	return 0;
}
