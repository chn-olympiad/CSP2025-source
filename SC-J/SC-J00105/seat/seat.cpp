#include<bits/stdc++.h>
using namespace std;
int n,m,s[230],b,c,d,e,f,a;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
    cin>>n>>m;
    int p=n*m;
    for(int i=1;i<=p;++i){
    	cin>>s[i];
    	b=s[1];
	}
	sort(s+1,s+p+1);
	for(int i=1;i<=p;++i){
		if(s[i]==b) a=i-1;
	}
	c=a/n;
	if(a%n!=0){
			cout<<c+1<<" ";
			e=(c+1)*n;
			if((c+1)%2==0)
			cout<<n-e+a;
			if(e==a) cout<<n;
			else{
				cout<<e-a;
			}	
		} 
		if(a%n==0){
			cout<<c<<" ";
			f=c*n;
			if(c%2==0)
			cout<<n-f+a;
			if(f==a) cout<<n;
			else{
				cout<<f-a;
			}
			
			
		} 
	if(c==0){
		cout<<1<<" "<<a;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 