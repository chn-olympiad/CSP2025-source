#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main ()
{
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	//zuihouyitilandexie
	//piandianfeng~
	//sheng2kengdingwenle
	int n;
	int a,b,c;
	cin >>n;
	if (n<3){
		cout <<0;
		return 0;
	}else{
		cin >>a>>b>>c;int maxn=max(a,c);
		maxn=max(maxn,b);
		if ((a+b+c)>maxn*2){
			cout <<1;
			return 0;
		}else {cout <<0;return 0;}
	}
	
	
	cout <<"CCF恢复人类一次";
	return 0;
}

