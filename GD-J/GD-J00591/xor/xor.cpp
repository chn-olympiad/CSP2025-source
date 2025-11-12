#include<bits/stdc++.h>
using namespace std;
string to2(int e){
	string s=" ";
	for(int q=0;q<25;q++){
			s+=(e%2);
			e/=2;
			if(e==0){
				break;
			}		
	}
	return s;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	vector<int> a;
	bool b[500000];
	
	for(long long i=0;i<500000;i++){
		b[i]=true;
	}
    for(int i=0;i<n;i++){
    	int k;
    	cin>>k;
    	a.push_back(k);
	} 
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int sum=a[i];
			    
			int c[25]={},d[25]={},f[25]={};
			for(int p=i;p<j;p++){
				string u=to2(sum);
				string g=to2(a[p+1]);
				if(!b[p]){
					break;
				}
				for(int i=0;i<max(u.size(),g.size());i++){
					c[i]=u[i]-'0';
					d[i]=g[i]-'0';
				}
				for(int i=0;i<max(u.size(),g.size());i++){
					if(c[i]==d[i]){
						f[i]=0;
					}else{
						f[i]=1;
					}
				}
				int y=1;
				sum=0;
			    for(int i=max(u.size(),g.size());i>0;i++){
			    	sum+=f[i]*y;
			    	y=y*2;
				}
			}
			if(sum==k){
				for(int h=i;h<=j;h++){
					b[h]=false;
					cnt++;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
