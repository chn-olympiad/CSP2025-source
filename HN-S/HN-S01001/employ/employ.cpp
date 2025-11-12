#include<bits/stdc++.h>
using namespace std;
int js(int x){
	int temp=x;
	int ans=1;
	while(temp!=0){
	    ans*=temp;
	    temp-=1;
    }
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int c[n+5]={0};
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int ls=s.length(),temp=0;
	for(int i=1;i<=ls;i++){
		if(s[i]=='1')
		    temp=1;
	}
	if(temp=0){
	    cout<<0;
	    return 0; 
	}
	int pmet=0;
	for(int i=1;i<=ls;i++){
		if(s[i]=='0')
		    pmet=1;
	}
	if(m==1||pmet==0){
	    cout<<js(n)%998244353;
	    return 0;
	}
	return 0;
} 
