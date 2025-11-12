#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
int c[505];
bool visited[505];
void func1(int step,int no,long long &ans,int ok){ 
	if(n-step+1+ok<m){
		return;
	}
	if(step>=n+1 && ok==m+2){
//		cout<<"++"<<endl;
		ans++;
		ans=ans%998244353;
		return; 
	}
	for(int i=1;i<=n;i++){
		if(!visited[i]){
//			cout<<i<<endl;
			visited[i]=1;
			if(no>=c[i] || (int)(s[step-1]-'0')==0){
//				if(no>=c[i]){
//					cout<<"error1"<<endl;
//				}else{
//					cout<<"error2"<<endl;
//				}
				func1(step+1,no+1,ans,ok);
			}else{
				func1(step+1,0,ans,ok+1);
			}
			visited[i]=0;
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
//	cout<<s<<endl;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	long long ans=0;
	if(n<=18){
		func1(1,0,ans,0);
	}else{
		if(m==n){
			bool flag=0;
			for(int i=1;i<=n;i++){
				if(c[i]==0){
					flag=1;
				} 
			}
			for(int i=0;i<n;i++){
				if(s[i]-'0'==0){
					flag=1;
				}
			}
			if(flag){
				cout<<0<<endl;
			}else{
				ans=1;
				for(int i=1;i<=n;i++){
					ans*=n;
					ans=ans%998244353;
				}
			}
		}else if(m==1){
			ans=1;
			for(int i=1;i<=n;i++){
				ans*=n;
				ans=ans%998244353;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
