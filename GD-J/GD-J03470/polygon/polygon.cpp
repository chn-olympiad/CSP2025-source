#include<bits/stdc++.h> 
using namespace std;
int ans,sf;
int a;
vector <int> k;
void sos(int t,int m,int sum,int c,char b){
	if(t==k.size()) return ;
	sos(t+1,max(m,k[t]),sum+k[t],c+1,'l');
	sos(t+1,m,sum,c,'r');
	
	
	if(b=='l'){
		sum+=k[t];
		c++;
		m=max(m,k[t]);
		if(2*m<sum and c>=3) {	
		ans++;
		ans%=998244353;
		cout<<t<<' '<<m<<' '<<sum<<' '<<c<<endl; 
		}
	}
	
	
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>sf;
		k.push_back(sf);
	}
	sos(0,0,0,0,'e');
	cout<<ans;
	return 0;
}
