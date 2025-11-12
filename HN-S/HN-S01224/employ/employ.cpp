#include<bits/stdc++.h>
using namespace std;

int jc(int tot){
	unsigned int t;
	for(int i=1;i<=tot;i++){
		t*=i;
		t%=998244353;
	}
	return t;
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int tot=s.size();
	cout<<jc(tot)<<endl;
	return 0;
} 
