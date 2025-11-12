#include<bits/stdc++.h>
using namespace std;
int n,m,p=1;
string s;
vector<int> c;
int fact(int a){
	int res=1;
	do{
		res*=a;res%=998244353;
	}while(--a);
}
int main(){freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		c.push_back(x);
	}
	sort(c.begin(),c.end());
	int cur=0,f=0,mn=c[0];
	for(int i=0;i<c.size();i++){
		cur++;
		if(s[i]==0||f>=c[i]){
			f++;
			if(f>=mn){
				mn=s[i+1];
				p*=fact(cur);
			}
			cur=0;
		}
	}
	cout<<p;
	fclose(stdin);fclose(stdout);
}
