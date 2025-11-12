//GZ-J00387 贵阳市第二实验中学 范思杨 
#include<bits/stdc++.h>
using namespace std;
int n,a[505],k,z,l,ans,s2,l2;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>k>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[0]=1;
	for(int i=1;i<=n;i++){
		a[0]*=i;
	}
	sort(a+1,a+n+1)
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			z++;
		}
	}
	l=z;
	ans=l;
	l2=0;
	for(int i=1;i<z;i++){
		s2=0;
		for(int j=1;j<=n;j++){
			if(a[j]<=l){
				ans*=l;
				s2++;
			}
		}
		l++;
		if((n-s2)>=k){
			l2++;
		}
	}
	cout<<a[0]-ans+l2;
	return 0;
}
