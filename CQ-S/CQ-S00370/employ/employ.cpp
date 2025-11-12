#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string h;
	cin>>h;
	char a[100000];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int r=0;
	int p=0;
	sort(a+1,a+1+n);
	int q=0;
	int y=0;
	for(int i=1;i<=n;i++){
		if(r==m){
			y+=(n-i)*(n-i+1)/2;
		}
		else if(h[i-1]=='1'){
			p++;
			r++;
			y+=q*(q+1)/2;
		}
		else if(h[i-1]=='0'){
			q++;
			y+=p*(p+1)/2;
		}
	}
	cout<<y;
	return 0;
}
