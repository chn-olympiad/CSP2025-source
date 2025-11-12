#include <bits/stdc++.h>
using namespace std;
int n,k,q[500010],ans,t,sum;
bool flag;
vector<int> v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	for (int i=0;i<n;i++){
		cin>>q[i];
		if (q[i]!=1) flag=1;
	}
	if (!flag){
		cout<<n/2;
	}
	else if (k<=1){
		t=0;
		for (int i=0;i<n;i++){
			v.push_back(q[i]);
			sum=q[t];
			for (int j=t+1;j<v.size();j++){
				sum=sum|v[j];
			}
			if (sum==k || q[i]==k){
				v.clear();
				ans++;
				t=i+1;
			}
			
			
		}
		cout<<ans;
		
		
	}
	else{
		
		t=0;
		for (int i=0;i<n;i++){
			v.push_back(q[i]);
			sum=q[t];
			for (int j=t+1;j<v.size();j++){
				sum=sum|v[j];
			}
			if (sum==k || q[i]==k){
				v.clear();
				ans++;
				t=i+1;
			}
			
			
		}			
		

		cout<<ans;			
		

		
	}
	
	
	return 0;
} 
