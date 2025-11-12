#include <bits/stdc++.h>
using namespace std;
long long n,sum;
long long q[5010],s[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>q[i];
		s[i] = s[i-1]+q[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j+i<=n;j++){
			int sumt = s[j+i]-s[i-1];
			
			if(sumt > q[j+i]*2){
				sum++;
				sum%=998244353;
				cout<<sumt<<" ";
				cout<<q[j+i]<<endl;
			}
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j+i<=n;j++){
			int t;
			int sumt = s[i-1] + s[n]-s[i+j-1];
			if(s[n]-s[i+j-1]!=0){
				t = q[n];
			}
			else{
				t = q[i-1];
			}
			
			if(sumt>t*2){
				sum++;
				sum%=998244353;
				cout<<sumt<<" "<<t<<endl;
			}
		}
	}
	cout<<sum;
	return 0;
} 
