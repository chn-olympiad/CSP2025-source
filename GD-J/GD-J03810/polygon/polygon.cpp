#include<bits/stdc++.h>
using namespace std;
long long b[5001],a[5001],n,s,m;
queue<long long>q1,q2; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(a[i],m);
	}
	if(m==1){
		cout<<((1<<n)-n-n*(n-1)/2-1)%998244353;
		return 0;
	}
	for(int i=3;i<=n;i++){
		b[i]=0;
		for(int j=i-1;j>0;j--){
			b[i]*=2;
			b[i]%=998244353;
			while(!q1.empty()){
				long long cc=q1.front()+a[j];
				q2.push(q1.front());
				q1.pop();
				if(cc>a[i])b[i]++;
				else q2.push(cc);
			}
			while(!q2.empty()){
				q1.push(q2.front());
				q2.pop();
			}
			q1.push(a[j]);
		}
		while(!q1.empty())q1.pop();
		s+=b[i];
		s%=998244353;
	}
	cout<<s;
	return 0;
} 

