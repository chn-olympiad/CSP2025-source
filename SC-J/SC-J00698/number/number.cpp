#include<bits/stdc++.h>
using namespace std;
string a;
int ans[1000001],j,maxx11,minn11=INT_MAX,aas,w=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]<='9'&&a[i]>='0'){
			ans[j]=a[i]-'0';
			if(maxx11<a[i]-'0') maxx11=a[i]-'0';
			if(minn11>a[i]-'0') minn11=a[i]-'0';
			j++;
		} 
	}
	if(maxx11==minn11){
		cout<<maxx11;
		return 0;
	}
	sort(ans,ans+j);
	for(int i=j-1;i>=0;i--) cout<<ans[i];
	return 0;
}