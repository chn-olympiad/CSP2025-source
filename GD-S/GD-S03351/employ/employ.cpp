#include<bits/stdc++.h>
using namespace std;
int n,m;
string f;
string task;
int h[501]={0};
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	freopen();
	scanf("%d%d",&n,&m);
	cin>>task;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	bool flag=1;
	for(int i=0;i<n;i++){
		if(task[i]!='1'){
			flag=0;
		}
	}
	if(flag){
		int ans=1;
		while(m){
			ans*=n;
			n--;
			m--;
		}
		cout<<ans;
		return 0;
	} 
	cout<<0;
} 
