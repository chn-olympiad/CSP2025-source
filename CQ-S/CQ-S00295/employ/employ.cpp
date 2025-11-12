#include<bits/stdc++.h>
using namespace std;
int n,m,x,b[505],c[505],MOD=998244353,num=0,kk=0;
vector<int> a,d;
string s;
int main(){
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>x;
		a.push_back(x);
		d.push_back(i);
	}
	b[0]=0;
	for(int i=0;i<n;i++){
		b[i]+=b[i-1];
		if(s[i]=='0'){
			c[i]=0;
			b[i+1]+=1;
		}else{
			c[i]=1;
		}
	}
	do{
		int ans=0;
		for(int i=0;i<n;i++){
			if(a[d[i]]>b[i]&&c[i]==1){
				ans++;
			}
		}
		if(ans>=m){
			num+=1;
		}
		kk+=1;
	}while(next_permutation(d.begin(),d.end()));
	cout<<num<<endl;
	return 0;
}
//3 2 101 1 1 2       2
//10 5 1101111011 6 0 4 2 1 2 5 4 3 3      2204128
