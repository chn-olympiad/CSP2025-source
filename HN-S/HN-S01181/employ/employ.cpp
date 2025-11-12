#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	char x;
	int n,m,per[505]={},tgs=0,tg=0;
	bool yin[505];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x=='0') yin[i]=false;
		else{
			yin[i]=true;
			tgs++;
		} 
	}
	for(int i=1;i<=n&&yin[i]==1;i++){
		tg++;
	}
	for(int i=1;i<=n;i++) cin>>per[i];
	if(tgs<m){
		cout<<0;
		return 0;
	}
	if(tg>=m){
		int a[501];
		a[1]=1;
		for(int i=2;i<=n;i++) a[i]=a[i-1]*i%998244353;
		cout<<a[n];
		return 0;
	}
	cout<<"谁来救救我，我要BK(AK的反义词)了";
	return 0;
}
