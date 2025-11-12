#include<bits/stdc++.h>
using namespace std;
int a[10000005];
bool cmp(int aa,int bb){
	return aa<bb;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int p=1;
	int q=1;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1])q++;
		else{
			p*=q;
			q=1;
		}
	}
	cout<<p;
} 
