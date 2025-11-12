#include<bits/stdc++.h>
using namespace std;
int n,m,c[1000],sum=1,ans=1;
string s;
int main(){
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	int t=n,x=0;
	for(int i=0;i<=s.size();i++){
		if(t<=0){
			break;
		}
		if(s[i]=='1'){
			ans*=(t-1);
			sum++;
			t--;
		}
		else{
			t--;
			x++;
		}int a=0;
		for(int i=1;i<=n;i++){
			if(c[i]<=x){
				t--;
				a++;
			}	
		}
		x+=a;
	}
	cout<<ans;
}
